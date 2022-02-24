#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=1706 lang=cpp
 *
 * [1706] 球会落何处
 */

// @lc code=start
class Solution {
    const int FAILED = -1;

   public:
    vector<int> findBall(const vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = m ? grid[0].size() : 0;
        auto canFall = vector<int>(n);
        auto isValidPostion = [=](int position) {
            return position >= 0 && position < n;
        };

        for (int i = 0; i < n; i++) {
            int ballPosition = i;
            for (int row = 0; row < m; row++) {
                int direction = grid[row][ballPosition];
                // 转移球的位置
                ballPosition += direction;
                // 判断转移后的位置是否合法
                if (!isValidPostion(ballPosition) ||
                    grid[row][ballPosition] != direction) {
                    ballPosition = FAILED;
                    break;
                }
            }
            canFall[i] = ballPosition;
        }
        return canFall;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto grid = j.get<vector<vector<int>>>();
        print(Solution().findBall(grid));
    }
}