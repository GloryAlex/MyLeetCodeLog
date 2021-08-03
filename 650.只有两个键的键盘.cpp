#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=650 lang=cpp
 *
 * [650] 只有两个键的键盘
 */

// @lc code=start
class Solution {
   public:
    int minSteps(int n) {
        int total = 0, d = 2;
        while (n > 1) {
            while (!(n % d)) {
                total += d;
                n /= d;
            }
            d++;
        }
        return total;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        int n;
        in >> n;
        print(Solution().minSteps(n));
    }
}