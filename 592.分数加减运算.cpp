#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=592 lang=cpp
 *
 * [592] 分数加减运算
 */

// @lc code=start
class Solution {
  class Fraction {
    using fraction_t = int;
    fraction_t denominator;
    fraction_t numerator;

   public:
    Fraction(int deno, int nume) {
      denominator = abs(deno);
      numerator = abs(nume);
      if (!deno) {
        numerator = 1;
        return;
      }
      const fraction_t GCD = gcd(denominator, numerator);
      denominator /= GCD;
      numerator /= GCD;
      if ((deno < 0) ^ (nume < 0)) {
        denominator = -denominator;
      }
    }
    Fraction reverse() const {
      Fraction result = Fraction(*this);
      result.denominator = -result.denominator;
      return result;
    }
    Fraction operator+(const Fraction& b) const {
      fraction_t nume = lcm(numerator, b.numerator);
      fraction_t deno = (nume / numerator) * denominator +
                        (nume / b.numerator) * b.denominator;
      return Fraction(deno, nume);
    }
    Fraction operator-(const Fraction& b) const {
      auto negativeB = b.reverse();
      return operator+(negativeB);
    }
    string toString(){
        return to_string(denominator)+"/"+to_string(numerator);
    }
    static Fraction valueOf(string::iterator begin, string::iterator end) {
      auto pos = begin;
      while (pos != end && *pos != '/') pos++;
      string deno = string(begin,pos);
      string nume = string(pos+1,end);
      return Fraction(stoi(deno), stoi(nume));
    }
  };

 public:
  string fractionAddition(string expression) {
    auto it = expression.begin()+1, end = expression.end();
    while (it != end && *it != '+' && *it != '-') it++;
    Fraction result = Fraction::valueOf(expression.begin(), it);
    while (it < end) {
      auto next = it + 1;
      while (next != end && *next != '+' && *next != '-') next++;
      Fraction cur = Fraction::valueOf(it + 1, next);
      if (*it == '+')
        result = result + cur;
      else
        result = result - cur;
      it = next;
    }
    return result.toString();
  }
};
// @lc code=end

int main() {
  ifstream in("input");
  while (!in.eof()) {
    string str;
    in >> str;
    str = getString(str);
    print(Solution().fractionAddition(str));
  }
}