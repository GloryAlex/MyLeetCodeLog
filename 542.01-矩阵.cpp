#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
class Solution {
    const vector<pair<int, int>> directions = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}};

   public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        auto result = vector<vector<int>>(m, vector<int>(n, -1));
        auto q = queue<pair<int, int>>();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!mat[i][j]) {
                    result[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        for (int steps = 1; !q.empty(); steps++) {
            int size = q.size();
            while (size--) {
                auto pos = q.front();
                q.pop();
                for (const auto direction : directions) {
                    int x = pos.first + direction.first;
                    int y = pos.second + direction.second;
                    if (x >= 0 && y >= 0 && x < m && y < n &&
                        result[x][y] == -1) {
                        result[x][y] = steps;
                        q.push({x, y});
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
        string str;
        in >> str;
        auto matrix = getMatrix(str);
        print(Solution().updateMatrix(matrix));
    }
}