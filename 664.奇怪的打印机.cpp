#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=664 lang=cpp
 *
 * [664] 奇怪的打印机
 */

// @lc code=start
class Solution {
public:
    int strangePrinter(string s) {
        int length=s.size();
        auto dp = vector<vector<int>>(length,vector<int>(length));
        for(int i=0;i<length;i++)dp[i][i]=1;
        for(int i=length-1;i>=0;i--){
            for(int j=i+1;j<length;j++){
                if(s[i]==s[j])dp[i][j]=dp[i][j-1];
                else{
                    dp[i][j]=INT_MAX;
                    for(int k=i;k<j;k++)dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
                }
            }
        }
        return dp[0][length-1];
    }
};
// @lc code=end
int main(){
ifstream in("input");
while(!in.eof()){
string str;
in>>str;
str=getString(str);
}
}
