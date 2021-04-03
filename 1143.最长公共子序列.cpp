#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp = vector<vector<int>>(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (text1[i] == text2[j])
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                else
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
        return dp[m][n];
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string s1, s2;
        in >> s1 >> s2;
        s1 = getString(s1), s2 = getString(s2);
        print(Solution().longestCommonSubsequence(s1, s2));
    }
}