#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 */

// @lc code=start
class Solution {
   public:
    string convertToBase7(int num) {
        if (num < 7 && num > -7) return to_string(num);
        
        bool isNegative = (num < 0);
        num = abs(num);
        string ret;
        while (num) {
            ret += to_string(num % 7);
            num /= 7;
        }
        if (isNegative) ret += "-";
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        int n;
        in >> n;
        cout << Solution().convertToBase7(n) << endl;
    }
}