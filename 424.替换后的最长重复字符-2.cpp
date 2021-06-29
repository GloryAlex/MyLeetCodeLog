#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=424 lang=cpp
 *
 * [424] 替换后的最长重复字符
 */

// @lc code=start
class Solution {
 public:
  int characterReplacement(string s, int k) {
    //更好的解法
    vector<int> dict(26);
    int historyMax = 0, left = 0;
    for (int right = 0; right < s.length(); right++) {
      int pos = s[right] - 'A';
      dict[pos]++;
      historyMax = max(historyMax, dict[pos]);
      if (right - left + 1 - historyMax > k) {
        dict[s[left++] - 'A']--;
      }
    }
    return s.length() - left;
  }
};
// @lc code=end

int main() {
  ifstream in("input");
  while (!in.eof()) {
    string str;
    int k;
    in >> str >> k;
    str = getString(str);
    print(Solution().characterReplacement(str, k));
  }
}