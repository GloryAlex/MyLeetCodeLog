#include "LeetCode.h"
#include<initializer_list> 
using namespace std;
/*
 * @lc app=leetcode.cn id=712 lang=cpp
 *
 * [712] 两个字符串的最小ASCII删除和
 */

// @lc code=start
class Solution {
    private:
    inline int min(int a,int b,int c){
        if(a>b)a=b;
        if(a>c)a=c;
        return a;
    }
   public:
    int minimumDeleteSum(string s1, string s2) {
        int len1 = s1.size(), len2 = s2.size();
        auto dp = vector<vector<int>>(len1 + 1, vector<int>(len2 + 1));

        for(int i=0;i<len1;i++)dp[i+1][0]=s1[i]+dp[i][0];
        for(int j=0;j<len2;j++)dp[0][j+1]=s2[j]+dp[0][j];

        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                if (s1[i] == s2[j])
                    dp[i + 1][j + 1] = dp[i][j];
                else
                    dp[i + 1][j + 1] = min(dp[i][j]+s1[i]+s2[j],dp[i+1][j]+s2[j],dp[i][j+1]+s1[i]);
            }
        }

        return dp[len1][len2];
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string s1, s2;
        in >> s1 >> s2;
        s1 = getString(s1);
        s2 = getString(s2);
        cout << Solution().minimumDeleteSum(s1, s2) << endl;
    }
}