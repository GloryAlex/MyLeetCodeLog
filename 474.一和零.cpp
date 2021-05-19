#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
class Solution {
   public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        /**
         * @member first: 字符串中 0 的个数
         * @member second: 字符串中 1 的个数
         */
        vector<pair<int, int>> counts;
        //统计字符数字的0/1计数
        for (const auto& str : strs) {
            int countOne = 0, countZero = 0;
            for (char i : str)
                if (i == '1')
                    countOne++;
                else
                    countZero++;
            counts.push_back({countZero, countOne});
        }
        //动态规划求解
        auto dp = vector<vector<int>>(m + 1, vector<int>(n + 1));
        for (const auto& count : counts) {
            for(int i=m;i>=count.first;i--){
                for(int j=n;j>=count.second;j--){
                    dp[i][j]=max(dp[i][j],1+dp[i-count.first][j-count.second]);
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
