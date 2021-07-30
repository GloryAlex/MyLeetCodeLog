#include "LeetCode.h"
#include <cstdio>
using namespace std;
/*
 * @lc app=leetcode.cn id=500 lang=cpp
 *
 * [500] 键盘行
 */

// @lc code=start
class Solution {
    string keyboard[3] = {"qwertyuiop","asdfghjkl","zxcvbnm"};
   public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char,int> dict;
        for(int i=0;i<3;i++){
            for(char j:keyboard[i]){
                dict[j]=i;
            }
        }
        auto isAllSame = [&](const string& str){
            int index = dict[tolower(str[0])];
            for(char i:str){
                if(dict[tolower(i)]!=index)return false;
            }
            return true;
        };
        vector<string> result;
        for(string& i:words){
            if(isAllSame(i))result.push_back(i);
        }
        return result;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = getStringArray(str);
        print(Solution().findWords(arr));
    }
}