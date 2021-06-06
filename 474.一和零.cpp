#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
class Solution {
    struct nature{
        int zeroCount;
        int oneCount;
    };
   public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        auto natures = vector<nature>();
        //统计字符数字的0/1计数
        for(const auto& str:strs){
            int zeroCount = 0;
            for(auto i:str)zeroCount+=(i=='0');
            natures.push_back(nature{zeroCount,(int)str.size()-zeroCount});
        }
        //动态规划求解
        auto dp = vector<vector<int>>(m+1,vector<int>(n+1));
        for(const auto& curNature:natures){
            for(int i=m;i>=curNature.zeroCount;i--){
                for(int j=n;j>=curNature.oneCount;j--){
                    dp[i][j]=max(dp[i][j],dp[i-curNature.zeroCount][j-curNature.oneCount]+1);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end
int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        int m, n;
        in >> str >> m >> n;
        auto arr = getStringArray(str);
        cout << Solution().findMaxForm(arr, m, n) << endl;
    }
}
