#include "LeetCode.h"
using namespace std;

/**
 * 记忆化搜索写法
 */
// class Solution
// {
//     typedef long long llong;
//     const int MOD = 1e9 + 7;
//     vector<vector<llong>> dp;
//     llong getNumWays(int remainSteps, int curIndex, int edgeIndex)
//     {
//         if (dp[remainSteps][curIndex] != -1)
//             return dp[remainSteps][curIndex];

//         auto noMove = getNumWays(remainSteps - 1, curIndex, edgeIndex);
//         auto leftMove = curIndex > 0 ? getNumWays(remainSteps - 1, curIndex - 1, edgeIndex) : 0L;
//         auto rightMove = curIndex < edgeIndex ? getNumWays(remainSteps - 1, curIndex + 1, edgeIndex) : 0L;

//         return dp[remainSteps][curIndex] = (noMove + leftMove + rightMove) % MOD;
//     }

// public:
//     int numWays(int steps, int arrLen)
//     {
//         arrLen=min(arrLen-1,steps);
//         dp = vector<vector<llong>>(steps+1, vector<llong>(arrLen+1, -1));
//         fill(dp[0].begin(), dp[0].end(), 0);
//         dp[0][0] = 1;

//         return getNumWays(steps,0,arrLen);
//     }
// };
/**
 * 动态规划写法
 * @Author: Glory Xie
 * @Version: 0.1 
*/
class Solution
{
public:
    int numWays(int steps, int arrLen)
    {
        //初始化dp数组
        const int MOD = 1e9 + 7;
        auto edgeIndex = min(arrLen - 1, steps);
        auto dp = vector<long long>(edgeIndex + 1);
        dp[0] = 1;
        //开始动态规划
        for (int i = 1; i <= steps; i++)
        {
            auto tempDp = vector<long long>(edgeIndex + 1);
            for (int j = 0; j <= edgeIndex; j++)
                tempDp[j] = (dp[j] + (j > 0 ? dp[j - 1] : 0) + (j < edgeIndex ? dp[j + 1] : 0)) % MOD;
            dp = tempDp;
        }
        //返回答案
        return dp[0];
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        int a, b;
        in >> a >> b;
        cout << Solution().numWays(a, b) << endl;
    }
}