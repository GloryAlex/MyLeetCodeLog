#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int s)
    {
        int length = nums.size();
        auto dp = vector<vector<int>>(length,vector<int>(2001));

        dp[0][nums[0]+1000]=1;
        dp[0][-nums[0]+1000]=1;

        for(int i=1;i<length;i++){
            for(int j=-1000;j<=1000;j++){
                if(dp[i-1][j+1000]>0){
                    dp[i][j+1000-nums[i]]+=dp[i-1][j+1000];
                    dp[i][j+1000+nums[i]]+=dp[i-1][j+1000];
                }
            }
        }
        return s>1000?0:dp.back().at(s+1000);
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        int s;
        in >> str >> s;
        auto arr = getArray(str);
        print(Solution().findTargetSumWays(arr, s));
    }
}