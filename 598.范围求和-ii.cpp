#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=598 lang=cpp
 *
 * [598] 范围求和 II
 */

// @lc code=start
class Solution {
   public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minX = m, minY = n;
        for (const auto& op : ops) {
            minX = min(minX, op[0]);
            minY = min(minY, op[1]);
        }
        return minX * minY;
    }
};
// @lc code=end

int main(int argc, const char* argv[]) {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        int m, n;
        in >> m >> n >> str;
        auto matrix = getMatrix(str);
        print(Solution().maxCount(m, n, matrix));
    }
}
