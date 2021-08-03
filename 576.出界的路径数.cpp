#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=576 lang=cpp
 *
 * [576] 出界的路径数
 */

// @lc code=start
class Solution {
    using llong   = long long;
    const int MOD = 1e9 + 7;
    vector<vector<vector<llong>>> moveChoices;
    const vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m, n;

   public:
    llong findAllPaths(int x, int y, int remain) {
        if (x < 0 || y < 0 || x >= m || y >= n)
            return 1;
        if (moveChoices[x][y][remain] != -1)
            return moveChoices[x][y][remain];

        llong curAns = 0;
        for (const auto direction : directions)
            curAns = (curAns + findAllPaths(x + direction.first, y + direction.second, remain - 1)) % MOD;
        return moveChoices[x][y][remain] = curAns;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        // 初始化全局变量
        this->moveChoices = vector<vector<vector<llong>>>(m, vector<vector<llong>>(n, vector<llong>(maxMove + 1, -1)));
        this->m           = m;
        this->n           = n;
        // 初始化边界
        for (auto& row : moveChoices)
            for (auto& col : row) col[0] = 0;
        // dfs寻找答案
        return findAllPaths(startRow, startColumn, maxMove);
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        int m, n, N, i, j;
        in >> m >> n >> N >> i >> j;
        print(Solution().findPaths(m, n, N, i, j));
    }
}