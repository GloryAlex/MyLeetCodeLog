#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 */

// @lc code=start
class Solution {
 public:
  string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) return "0";
    if (denominator == 0) return "0";
    typedef long long llong;
    bool isNegative = (numerator < 0) ^ (denominator < 0);
    llong nume = abs((llong)numerator), deno = abs((llong)denominator);
    //计算整数部分
    string wholeNumber = (isNegative ? "-" : "") + to_string(nume / deno);
    nume %= deno;
    //记录被除数
    unordered_map<llong, int> seen;
    //循环计算
    string decimal = "";
    for (int i = 0; nume; i++) {
      nume *= 10;
      if (seen.count(nume)) {
        decimal.insert(decimal.begin() + seen[nume], '(');
        decimal.push_back(')');
        break;
      }
      seen[nume] = i;
      decimal += to_string(nume / deno);
      nume %= deno;
    }
    if (!decimal.empty()) wholeNumber += "." + decimal;

    return wholeNumber;
  }
};
// @lc code=end
int main() {
  ifstream in("input");
  while (!in.eof()) {
    int a, b;
    in >> a >> b;
    print(Solution().fractionToDecimal(a, b));
  }
}