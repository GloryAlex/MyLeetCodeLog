#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=401 lang=cpp
 *
 * [401] 二进制手表
 */

// @lc code=start
class Solution {
  vector<string> ret;

 public:
  vector<string> readBinaryWatch(int turnedOn) {
    if (turnedOn > 8) return {};  //不可能同时亮超过8个灯
    dfs(0, 0, turnedOn);
    return ret;
  }
  void dfs(int mask, int index, int remain) {
    if (index > 10 || remain > 10 - index) return;
    if (remain == 0) {
      auto time = toTime(mask);
      if (!time.empty()) ret.emplace_back(time);
      return;
    }
    dfs(mask, index + 1, remain);
    dfs(mask | (1 << index), index + 1, remain - 1);
  }
  string toTime(int mask) {
    int hour = (mask & ((1 << 4) - 1));
    int second = mask >> 4;
    if (hour >= 12 || second >= 60) return "";
    return to_string(hour) + (second < 10 ? ":0" : ":") + to_string(second);
  }
};
// @lc code=end
int main() {
  ifstream in("input");
  while (!in.eof()) {
    int lightCount;
    in >> lightCount;
    print(Solution().readBinaryWatch(lightCount));
  }
}
