#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=482 lang=cpp
 *
 * [482] 密钥格式化
 */

// @lc code=start
class Solution {
    char upper(char i){
        return i>='a'&&i<='z'?i+'A'-'a':i;
    }
   public:
    string licenseKeyFormatting(string s, int k) {
        int length = 0;
        string ret = "";
        for(int i=(int)s.size()-1;i>=0;i--){
            if(s[i]=='-')continue;
            ret.push_back(upper(s[i]));
            length++;
            if(length%k==0)ret.push_back('-');
        }
        if(ret.back()=='-')ret.pop_back();
        reverse(ret.begin(),ret.end());
        return ret;
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
        print(Solution().licenseKeyFormatting(str, k));
    }
}