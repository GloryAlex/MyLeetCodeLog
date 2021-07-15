#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=537 lang=cpp
 *
 * [537] 复数乘法
 */

// @lc code=start
class Solution {
    class Complex {
        int fact;
        int vir;

       public:
        Complex(int fact, int vir) {
            this->fact = fact;
            this->vir  = vir;
        }
        Complex operator*(Complex a) const {
            int nextFact = fact * a.fact - vir * a.vir;
            int nextVir  = fact * a.vir + a.fact * vir;
            return Complex(nextFact, nextVir);
        }
        string toString() {
            return to_string(fact) + "+" + to_string(vir) + "i";
        }
        static Complex valueOf(string s) {
            auto pos = s.begin();
            while (*pos != '+') pos++;
            return Complex(stoi(string(s.begin(), pos)), stoi(string(pos + 1, s.end() - 1)));
        }
    };

   public:
    string complexNumberMultiply(string num1, string num2) {
        return (Complex::valueOf(num1) * Complex::valueOf(num2)).toString();
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string s1, s2;
        in >> s1 >> s2;
        s1 = getString(s1);
        s2 = getString(s2);
        print(Solution().complexNumberMultiply(s1, s2));
    }
}