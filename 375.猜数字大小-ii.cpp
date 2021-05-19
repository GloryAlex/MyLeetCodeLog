#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=375 lang=cpp
 *
 * [375] 猜数字大小 II
 */

// @lc code=start
class Solution {
   public:
    int getMoneyAmount(int n) {
        //TODO: 完成动态规划解答
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        int n;
        in >> n;
        cout << Solution().getMoneyAmount(n) << endl;
    }
}