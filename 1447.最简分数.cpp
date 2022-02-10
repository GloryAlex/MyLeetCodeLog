#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=1447 lang=cpp
 *
 * [1447] 最简分数
 */

// @lc code=start
class Solution {
   public:
    vector<string> simplifiedFractions(int n) {
        auto result = vector<string>();
        for (int denominator = 2; denominator <= n; denominator++) {
            for (int numerator = 1; numerator < denominator; numerator++) {
                if (gcd(numerator, denominator) == 1) {
                    result.push_back(to_string(numerator) + "/" +
                                     to_string(denominator));
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
        int n;
        in >> n;
        print(Solution().simplifiedFractions(n));
    }
}