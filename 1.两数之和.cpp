#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int,int> dict;
        for(int i=0;i<nums.size();i++){
            int realTarget = target - nums[i];
            if(dict.count(realTarget))return {i,dict[realTarget]};
            else dict[nums[i]]=i;
        }
        return {-1,-1};
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
        print(Solution().twoSum(arr, k));
    }
}