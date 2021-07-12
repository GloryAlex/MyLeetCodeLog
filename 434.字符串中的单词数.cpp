#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 */

// @lc code=start
class Solution {
   public:
    int countSegments(string s) {
        int total = 0, i = 0;
        while (s[i] == ' ') i++;
        for (; i < s.length(); total++) {
            int j = i + 1;
            while (j != s.length() && s[j] != ' ') j++;
            while (j != s.length() && s[j] == ' ') j++;
            i = j;
        }
        return total;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        getline(in, str);
        str = getString(str);
        print(Solution().countSegments(str));
    }
}