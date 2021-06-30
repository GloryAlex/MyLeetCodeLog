#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */

// @lc code=start
class Solution {
 public:
  int minDistance(string word1, string word2) {
    int m = word1.length(), n = word2.length();
    if (m < n) return minDistance(word2, word1);
    auto dp = vector<int>(n + 1);
    for (int i = 1; i <= m; i++) {
      auto prev = dp;
      for (int j = 1; j <= n; j++) {
        if (word1[i - 1] == word2[j - 1])
          dp[j] = prev[j - 1] + 1;
        else
          dp[j] = max(prev[j], dp[j - 1]);
      }
    }
    return m + n - 2 * dp[n];
  }
};
// @lc code=end
int main() {
  ifstream in("input");
  while (!in.eof()) {
    string s1, s2;
    in >> s1 >> s2;
    s1 = getString(s1), s2 = getString(s2);
    print(Solution().minDistance(s1, s2));
  }
}