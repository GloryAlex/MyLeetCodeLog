#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=537 lang=cpp
 *
 * [537] 复数乘法
 */

// @lc code=start
class Solution {
    class Complex {
       private:
        const int fact;
        const int vir;

       public:
        Complex(int x, int y) : fact(x), vir(y) {}
        Complex operator*(Complex b) {
            int nextFact = fact * b.fact - vir * b.vir;
            int nextVir = vir * b.fact + b.vir * fact;
            return Complex(nextFact, nextVir);
        }
        string toString() {
            return to_string(fact) + "+" + to_string(vir) + "i";
        }
        static optional<Complex> valueOf(string s) {
            if (s.empty() || s.back() != 'i') return nullopt;
            auto i = find(s.begin(), s.end(), '+');
            if (i == s.end()) return nullopt;

            try {
                int fact = stoi(string(s.begin(), i));
                int vir = stoi(string(i + 1, s.end()));
                return Complex(fact, vir);
            } catch (...) {
                return nullopt;
            }
        }
    };

   public:
    string complexNumberMultiply(string num1, string num2) {
        return (*Complex::valueOf(num1) * *Complex::valueOf(num2)).toString();
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    json j;
    while (!in.eof()) {
        in >> j >> ws;
        string s1 = j.get<string>();
        in >> j >> ws;
        string s2 = j.get<string>();
        print(Solution().complexNumberMultiply(s1, s2));
    }
}