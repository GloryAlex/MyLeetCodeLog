#include "lib/leetcode.h"
using namespace std;

class Solution {
   private:
    const long long INF = LONG_MAX;
    using Graph = vector<unordered_map<int, long long>>;
    struct Point {
        int next;
        long long weight;
        bool operator<(const Point b) const { return weight > b.weight; }
        static Point valueOf(const pair<int, int> pii) {
            return {pii.first, pii.second};
        }
    };
    vector<long long> dijistra(int src, const Graph& graph, const int n) {
        priority_queue<Point> q;
        vector<bool> hasVisit(n, false);
        vector<long long> distance(n, INF);

        distance[src] = 0;
        q.push({src, 0});
        while (!q.empty()) {
            auto [id, weight] = q.top();
            q.pop();
            if (hasVisit[id])
                continue;
            else
                hasVisit[id] = true;

            for (const auto [j, weight] : graph[id]) {
                if (distance[j] > distance[id] + weight) {
                    distance[j] = distance[id] + weight;
                    q.push({j, distance[j]});
                }
            }
        }
        return distance;
    }

   public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1,
                            int src2, int dest) {
        auto graph = Graph(n);
        auto reGraph = Graph(n);
        for (const auto& edge : edges) {
            int begin = edge[0], end = edge[1];
            long long weight = edge[2];

            if (graph[begin].count(end)) {
                graph[begin][end] = min(graph[begin][end], weight);
            } else {
                graph[begin][end] = weight;
            }
            reGraph[end][begin] = graph[begin][end];
        }

        auto s1 = dijistra(src1, graph, n);
        auto s2 = dijistra(src2, graph, n);
        auto d = dijistra(dest, reGraph, n);

        long long res = INF;
        for (int i = 0; i < n; i++) {
            if (s1[i] != INF && s2[i] != INF && d[i] != INF)
                res = min(res, s1[i] + s2[i] + d[i]);
        }
        return res == INF ? -1 : res;
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json jj;
        int n;
        in >> n >> jj >> ws;
        auto arr = jj.get<vector<vector<int>>>();
        int i, j, k;
        in >> i >> j >> k >> ws;
        print(Solution().minimumWeight(n, arr, i, j, k));
    }
}