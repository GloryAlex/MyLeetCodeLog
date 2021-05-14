#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 */

// @lc code=start
class Solution {
    int getArithmeticSlicesSimply(vector<int>& nums)
    {
        int total = 0;
        for (int i = 0, length = nums.size(); i < length - 2; i++) {
            int diff = nums[i + 1] - nums[i];
            for (int k = i + 2; k < length; k++) {
                if (nums[k] - nums[k - 1] == diff)
                    total++;
                else
                    break;
            }
        }
        return total;
    }

    int getArithmeticsSlicesByDynamicProgram(vector<int>& nums)
    {
        auto dp = vector<int>(nums.size());
        for(int i=2;i<nums.size();i++){
            dp[i]=(nums[i]-nums[i-1]==nums[i-1]-nums[i-2])?dp[i-1]+1:0;
        }
        return accumulate(dp.begin(),dp.end(),0);
    }

public:
    int numberOfArithmeticSlices(vector<int>& nums)
    {
        return getArithmeticsSlicesByDynamicProgram(nums);
    }
};
// @lc code=end
int main()
{
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = getArray(str);
        cout << Solution().numberOfArithmeticSlices(arr) << endl;
    }
}
