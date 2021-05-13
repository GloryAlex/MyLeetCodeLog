#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        auto ret = vector<vector<int>>();
        for (auto first = nums.begin(); first < nums.end(); first++)
        {
            if (first > nums.begin() && *first == *(first - 1))
                continue;
            auto second = first + 1, third = nums.end() - 1;
            while (second < third)
            {
                int curSum = *first + *second + *third;
                if ((second > first + 1 && *second == *(second - 1)) || curSum < 0)
                    second++;
                else if (!curSum)
                    ret.push_back({*first, *second++, *third--});
                else
                    third--;
            }
        }
        return ret;
    }
};
// @lc code=end

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        in >> str;
        auto arr = getArray(str);
        auto ret = Solution().threeSum(arr);
        print(ret);
    }
}
