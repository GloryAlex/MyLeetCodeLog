#include <regex>

#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=640 lang=cpp
 *
 * [640] 求解方程
 */

// @lc code=start
class Solution {
    class Expression {
        int coef     = 0;
        int constant = 0;

       public:
        Expression(int coef, int constant) {
            this->coef     = coef;
            this->constant = constant;
        }
        static Expression valueOf(const string& str) {
            int coef     = 0;
            int constant = 0;
            for (int i = 0; i < str.length();) {
                int j = i + 1;
                while (j < str.length() && isdigit(str[j])) j++;
                int cur = stoi(str.substr(i, j - i));
                if (j < str.length() && str[j] == 'x') {
                    coef += cur;
                    j++;
                } else {
                    constant += cur;
                }
                i = j;
            }
            return Expression(coef, constant);
        }
        pair<int, int> equal(Expression e) {
            int left  = coef - e.coef;
            int right = e.constant - constant;
            if (left && right) {
                int GCD = gcd(left, right);
                left /= GCD;
                right /= GCD;
            }
            return {left, right};
        }
    };
    string addOne(string& s){
        string ret;
        for(int i=0;i<s.length();i++){
            if(s[i]=='x'&&(i==0||!isdigit(s[i-1])))ret+="1x";
            else ret.push_back(s[i]);
        }
        return ret;
    }
   public:
    string solveEquation(string equation) {
        equation=addOne(equation);
        auto i = equation.begin();
        while (*i != '=') i++;
        auto left  = Expression::valueOf(string(equation.begin(), i));
        auto right = Expression::valueOf(string(i + 1, equation.end()));
        auto e     = left.equal(right);
        if (e.first == 0) {
            if (e.second == 0)
                return "Infinite solutions";
            else
                return "No solution";
        }
        return "x=" + to_string(e.second / e.first);
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        str = getString(str);
        print(Solution().solveEquation(str));
    }
}