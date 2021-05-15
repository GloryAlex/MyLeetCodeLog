#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
   public:
    int romanToInt(string s) {
        unordered_map<char, int> dict = {{'M', 1000}, {'D', 500}, {'C', 100},
                                           {'L', 50},   {'X', 10},  {'V', 5},
                                           {'I', 1}};
        int ret = 0;
        for (int i = 0,length=s.size(); i < length; i++) {
            if(i<length-1&&dict[s[i]]<dict[s[i+1]])ret-=dict[s[i]];
            else ret+=dict[s[i]];
        }   
        return ret;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        str = getString(str);
        cout << Solution().romanToInt(str) << endl;
    }
}