#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=313 lang=cpp
 *
 * [313] 超级丑数
 */

// @lc code=start
class Solution {
 public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    typedef long long llong;
    auto dp = vector<llong>(n + 1, LLONG_MAX);
    auto coefficients = vector<pair<int, int>>();
    for(int i:primes)coefficients.push_back({1,i});
    
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
    string str;
    in >> n >> str;
    auto arr = getArray(str);
    print(Solution().nthSuperUglyNumber(n, arr));
  }
}