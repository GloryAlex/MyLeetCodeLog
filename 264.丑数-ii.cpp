#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution {
 public:
  int nthUglyNumber(int n) {
    typedef long long llong;
    
    auto dp = vector<llong>(n + 1, LLONG_MAX);
    auto coefficients = vector<pair<int, int>>{{1, 2}, {1, 3}, {1, 5}};
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      for (auto coef : coefficients) {
        dp[i] = min(dp[i], dp[coef.first] * coef.second);
      }
      for (auto& coef : coefficients) {
        if (dp[i] == (dp[coef.first] * coef.second)) coef.first++;
      }
    }
    return dp[n];
  }
};
// @lc code=end

int main() {
  ifstream in("input");
  while (!in.eof()) {
    int n;
    in >> n;
    print(Solution().nthUglyNumber(n));
  }
}