#include "LeetCode.h"
using namespace std;

/*
 * @lc app=leetcode.cn id=403 lang=cpp
 *
 * [403] 青蛙过河
 */

// @lc code=start
class Solution
{
    vector<vector<int>> dp;
    bool canCrossWhenK(vector<int> &stones, int k, int position)
    {
        if(dp[k][position]!=-1)return dp[k][position];
        
        for (int offset = -1; offset <= 1; offset++)
        {
            int nextJump = stones[position] + k + offset;
            for (int index = position + 1; index < stones.size() && stones[index] <= nextJump; index++)
            {
                if (stones[index] == nextJump){
                    if (canCrossWhenK(stones, k+offset, index))
                        return dp[k][position] = true;
                    else
                        break;
                }
            }
        }
        return dp[k][position] = false;
    }

public:
    bool canCross(vector<int> &stones)
    {
        if(stones[1]-stones[0]!=1)return false;

        dp = vector<vector<int>>(stones.size()+1,vector<int>(stones.size(),-1));
        for(int i=0;i<=stones.size();i++)dp[i][(int)stones.size()-1]=true;
        return canCrossWhenK(stones,1,1);
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
        print(Solution().canCross(arr));
    }
}