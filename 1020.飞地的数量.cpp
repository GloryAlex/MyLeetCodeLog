#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 *
 * [1020] 飞地的数量
 */

// @lc code=start
class Solution {
   public:
    int numEnclaves(vector<vector<int>>& grid) {
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int m = grid.size();
        int n = m ? grid[0].size() : 0;
        auto isValidPosition = [&](int x, int y) {
            return x >= 0 && y >= 0 && x < m && y < n;
        };
        function<void(int, int)> dfs;
        dfs = [&](int x, int y) {
            if (isValidPosition(x, y) && grid[x][y]) {
                grid[x][y] = 0;
                for (auto [xOffset, yOffset] : directions) {
                    dfs(x + xOffset, y + yOffset);
                }
            }
        };
        // 检查边界上的陆地，逐个进行 dfs
        for (int i = 0; i < m; i++) {
            dfs(i, 0);
            dfs(i, n - 1);
        }
        for (int i = 1; i < n - 1; i++) {
            dfs(0, i);
            dfs(m - 1, i);
        }
        // 计算飞地数
        int result = 0;
        for (const auto& row : grid) {
            result += accumulate(row.begin(), row.end(), 0);
        }
        return result;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto grid = j.get<vector<vector<int>>>();
        print(Solution().numEnclaves(grid));
    }
}