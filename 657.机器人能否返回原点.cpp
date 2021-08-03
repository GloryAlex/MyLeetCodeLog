#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=657 lang=cpp
 *
 * [657] 机器人能否返回原点
 */

// @lc code=start
class Solution {
   public:
    bool judgeCircle(string moves) {
        unordered_map<char,int> dict;
        for(char i:moves)dict[i]++;
        return dict['U']==dict['D']&&dict['L']==dict['R'];
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        str = getString(str);
        print(Solution().judgeCircle(str));
    }
}