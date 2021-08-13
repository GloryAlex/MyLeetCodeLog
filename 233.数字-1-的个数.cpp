#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字 1 的个数
 */

// @lc code=start
class Solution {
    vector<int> dp = {0, 1, 20, 300, 4000, 50000, 600000, 7000000, 80000000, 900000000};

   public:
    int countDigitOne(int n) {
        long long res = 0;
        for (long long i = 1; i <= n; i *= 10) {
            res += (n / (i * 10)) * i;
            if (n / i % 10 > 1)
                res += i;
            else if (n / i % 10 == 1)
                res += n % i + 1;
        }
        return res;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        int n;
        in >> n;
        print(Solution().countDigitOne(n));
    }
}