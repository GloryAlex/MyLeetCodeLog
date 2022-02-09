#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 */

// @lc code=start
class Solution {
   public:
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<pair<int, int>> offsets = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        int result = 0;
        for (int x = 0, m = grid.size(); x < m; x++) {
            for (int y = 0, n = grid[x].size(); y < n; y++) {
                if (grid[x][y]) {
                    for (const auto [xOffset, yOffset] : offsets) {
                        int checkPointX = x + xOffset,
                            checkPointY = y + yOffset;
                        if (checkPointX < 0 || checkPointX >= m ||
                            checkPointY < 0 || checkPointY >= n ||
                            grid[checkPointX][checkPointY] == 0)
                            result++;
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
        json j;
        in >> j >> ws;
        auto grid = j.get<vector<vector<int>>>();
        print(Solution().islandPerimeter(grid));
    }
}