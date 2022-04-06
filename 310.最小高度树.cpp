#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */

// @lc code=start
class Solution {
   public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        auto grids = vector<vector<int>>(n);
        auto degreeOf = vector<int>(n);
        for (const auto& edge : edges) {
            int in = edge[0], out = edge[1];
            grids[in].push_back(out);
            grids[out].push_back(in);

            degreeOf[in]++;
            degreeOf[out]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degreeOf[i] <= 1) {
                q.push(i);
                degreeOf[i]--;
            }
        }
        auto result = vector<int>(n);
        while (!q.empty()) {
            int size = q.size();
            result.clear();
            while (size--) {
                auto cur = q.front();
                q.pop();
                result.push_back(cur);
                for (int next : grids[cur]) {
                    if (--degreeOf[next] == 1) {
                        q.push(next);
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        int n;
        json j;
        in >> n >> j >> ws;
        auto edge = j.get<vector<vector<int>>>();
        print(Solution().findMinHeightTrees(n, edge));
    }
}