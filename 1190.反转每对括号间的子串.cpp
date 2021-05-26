#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=1190 lang=cpp
 *
 * [1190] 反转每对括号间的子串
 */

// @lc code=start
class Solution {
   public:
    string reverseParentheses(string s) {
        stack<string::iterator> stk;
        for(auto i=s.begin();i!=s.end();i++){
            if(*i=='(')stk.push(i);
            else if(*i==')'){
                auto pre = stk.top();
                stk.pop();
                reverse(pre,i+1);
            }
        }
        int i=0,j=0;
        for(;j<s.size();j++){
            if(s[j]!='('&&s[j]!=')')s[i++]=s[j];
        }
        s.resize(i);
        return s;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        str = getString(str);
        cout << Solution().reverseParentheses(str) << endl;
    }
}