#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2的幂
 */

// @lc code=start
class Solution {
   public:
    bool isPowerOfTwo(int n) {
        return n>0 && !(n&(n-1));
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        int str;
        in >> str;
        print(Solution().isPowerOfTwo(str));
    }
}