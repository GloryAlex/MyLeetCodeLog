#include "LeetCode.h"
using namespace std;

class Solution {
    public:
    int stoneGameVIII(vector<int>& stones) {
        //计算前缀和
        auto preSum=vector<int>(stones);
        for(int i=1;i<preSum.size();i++)preSum[i]+=preSum[i-1];
        //动态规划求解问题
        auto dp = vector<int>(preSum.size());
        dp.back()=preSum.back();
        for(int i=(int)preSum.size()-2;i>=1;i--){
            dp[i]=max(dp[i+1],preSum[i]-dp[i+1]);
        }
        return dp[1];
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = getArray(str);
        cout << Solution().stoneGameVIII(arr)<<endl;
    }
}