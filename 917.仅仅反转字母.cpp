#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */

// @lc code=start
class Solution {
   public:
    string reverseOnlyLetters(string s) {
        int i=0,j=(int)s.size()-1;
        while(i<j){
            while(i<j && !isalpha(s[i]))i++;
            while(i<j && !isalpha(s[j]))j--;
            swap(s[i++],s[j--]);
        }
        return s;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        print(Solution().reverseOnlyLetters(j.get<string>()));
    }
}