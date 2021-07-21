#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=553 lang=cpp
 *
 * [553] 最优除法
 */

// @lc code=start
class Solution {
    vector<vector<double>> dp;

   public:
    string optimalDivision(vector<int>& nums) {
        int length    = nums.size();
        string result = to_string(nums[0]);
        if (length == 1)
            return result;
        else if (length == 2)
            return result + "/" + to_string(nums[1]);
        result += "/(" + to_string(nums[1]);
        for (int i = 2; i < length; i++) {
            result += "/" + to_string(nums[i]);
        }
        return result + ")";
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = getArray(str);
        print(Solution().optimalDivision(arr));
    }
}