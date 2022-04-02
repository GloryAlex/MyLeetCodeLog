#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 */

// @lc code=start
class Solution {
   public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<pair<int, int>> allPoints;
        auto maxPath = vector<vector<int>>(m, vector<int>(n, -1));
        auto directions =
            vector<pair<int, int>>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        auto isValid = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };
        function<int(int, int)> dfs;
        dfs = [&](int x, int y) -> int {
            if (maxPath[x][y] != -1) return maxPath[x][y];
            int pathLength = 0;
            for (const auto [xOffset, yOffset] : directions) {
                int nextX = x + xOffset, nextY = y + yOffset;
                if (isValid(nextX, nextY) &&
                    matrix[nextX][nextY] > matrix[x][y]) {
                    pathLength = max(pathLength, dfs(nextX, nextY));
                }
            }
            return maxPath[x][y] = pathLength + 1;
        };

        int res = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                res = max(res, dfs(i, j));
        return res;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto matrix = j.get<vector<vector<int>>>();
        cout << Solution().longestIncreasingPath(matrix) << endl;
    }
}