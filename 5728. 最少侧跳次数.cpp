#include "LeetCode.h"
using namespace std;

class Solution
{
    inline int min(int a,int b,int c){
        if(a>b)a=b;
        return a<c?a:c;
    }
public:
    int minSideJumps(vector<int> &obstacles)
    {
        int length = obstacles.size();
        vector<vector<int>> dp = vector<vector<int>>(3,vector<int>(length,INT_MAX-1));
        dp[1][0]=0;
        dp[0][0]=dp[2][0]=1;
        if(obstacles[0]>0)dp[obstacles[0]-1][0]=INT_MAX;
        

        for(int i=1;i<length;i++){
            int obstaclePosition = obstacles[i]-1;
            for(int n=0;n<=2;n++){
                if(n!=obstaclePosition)dp[n][i]=dp[n][i-1];
            }

            if(0!=obstaclePosition)dp[0][i]=min(dp[0][i],dp[1][i]+1,dp[2][i]+1);
            if(1!=obstaclePosition)dp[1][i]=min(dp[0][i]+1,dp[1][i],dp[2][i]+1);
            if(2!=obstaclePosition)dp[2][i]=min(dp[0][i]+1,dp[1][i]+1,dp[2][i]);
        }

        return min(dp[0].back(),dp[1].back(),dp[2].back());
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        in >> str;
        auto arr = getArray(str);
        cout << Solution().minSideJumps(arr)<<endl;
    }
}