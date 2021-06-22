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
    auto coefficients = vector<int>{2, 3, 5};
    auto pointers = vector<int>{1, 1, 1};
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      for (int j = 0; j < 3; j++) {
        dp[i] = min(dp[i], dp[pointers[j]] * coefficients[j]);
      }
      for (int j = 0; j < 3; j++) {
        if (dp[i] == dp[pointers[j]] * coefficients[j]) pointers[j]++;
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