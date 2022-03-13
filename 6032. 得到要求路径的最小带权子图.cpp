#include "lib/leetcode.h"
using namespace std;

class Solution {
   public:
    vector<vector<int>> graph;
    const int INF = 1e9;
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1,
                            int src2, int dest) {
        graph = vector<vector<int>>(n, vector<int>(n, INF));
        for (const auto& edge : edges) {
            int begin = edge[0], end = edge[1], weight = edge[2];
            graph[begin][end] = min(graph[begin][end], weight);
        }
        // todo
    }

};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        int n;
        in >> n >> j >> ws;
        auto arr = j.get<vector<vector<int>>>();
        int i, j, k;
        in >> i >> j >> k >> ws;
        print(Solution().minimumWeight(n, arr, i, k, k));
    }
}