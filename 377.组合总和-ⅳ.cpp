#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
class Solution
{
    vector<int> dp;
    int getCombinationSum(vector<int> &nums, int target)
    {
        if (dp[target] != -1)
            return dp[target];
        int total = 0;
        for (int i : nums)
        {
            if (target < i)
                break;
            else
                total += getCombinationSum(nums, target - i);
        }
        return dp[target] = total;
    }

public:
    int combinationSum4(vector<int> &nums, int target)
    {
        dp = vector<int>(target + 1, -1);
        dp[0] = 1;
        sort(nums.begin(), nums.end());
        return getCombinationSum(nums, target);
    }
};
// @lc code=end

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        int k;
        in >> str >> k;
        auto arr = getArray(str);
        print(Solution().combinationSum4(arr, k));
    }
}