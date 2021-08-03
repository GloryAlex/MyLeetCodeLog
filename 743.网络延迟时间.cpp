#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 */

// @lc code=start
class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        using llong = long long;
        using node = pair<int, int>;
        const auto INF = INT_MAX + 1LL;
        auto graph = vector<vector<node>>(n);
        for (const auto& time : times)
            graph[time[0] - 1].push_back({time[1] - 1, time[2]});
        auto hasVisit = vector<int>(n);
        auto dist = vector<long long>(n, INF);
        auto minOfUncharted = [&]() {
            pair<int, llong> result = {-1, INF};
            for (int i = 0; i < n; i++) {
                if (!hasVisit[i] && dist[i] < result.second)
                    result = {i, dist[i]};
            }
            return result;
        };

        dist[k - 1] = 0;
        for (int i = 0; i < n; i++) {
            const auto [id, _] = minOfUncharted();
            if (id == -1) break;
            hasVisit[id] = true;
            for (const auto i : graph[id]) {
                int dest = i.first;
                llong distance = i.second;
                if (!hasVisit[dest] && distance + dist[id] < dist[dest])
                    dist[dest] = distance + dist[id];
            }
        }
        llong longestDistance = *max_element(dist.begin(), dist.end());
        return longestDistance == INF ? -1 : (int)longestDistance;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        int n, k;
        in >> str >> n >> k;
        auto arr = getMatrix(str);
        print(Solution().networkDelayTime(arr, n, k));
    }
}