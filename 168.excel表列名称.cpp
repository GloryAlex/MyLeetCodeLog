#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

// @lc code=start
class Solution {
 public:
  string convertToTitle(int columnNumber) {
    vector<int> tempResult;
    while (columnNumber) {
      columnNumber--;
      tempResult.push_back(columnNumber % 26);
      columnNumber /= 26;
    }
    string result;
    for (auto i = tempResult.rbegin(); i != tempResult.rend(); i++) {
      result.push_back(*i + 'A');
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
    print(Solution().convertToTitle(n));
  }
}