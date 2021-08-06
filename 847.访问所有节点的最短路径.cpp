#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=847 lang=cpp
 *
 * [847] 访问所有节点的最短路径
 */

// @lc code=start
class Solution {
   public:
    int shortestPathLength(vector<vector<int>>& graph) {
        const int length = graph.size();
        queue<tuple<int, int, int>> q;  // id, status, dist
        vector<vector<short>> hasVisit(length, vector<short>(1 << length));
        int target = (1 << length) - 1;
        // initialize
        for (int i = 0; i < length; i++) {
            q.push({i, 1 << i, 0});
            hasVisit[i][1 << i] = true;
        }
        while (!q.empty()) {
            auto [id, status, dist] = q.front();
            q.pop();
            if (status == target) return dist;
            for (int next : graph[id]) {
                int nextStatus = (status | (1 << next));
                if(!hasVisit[next][nextStatus]){
                    q.push({next,nextStatus,dist+1});
                    hasVisit[next][nextStatus]=true;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto graph = getMatrix(str);
        print(Solution().shortestPathLength(graph));
    }
}