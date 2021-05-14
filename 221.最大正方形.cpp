#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int rowLength = matrix.size(), colLength = matrix.empty() ? 0 : matrix[0].size();
        auto dp = vector<vector<int>>(rowLength + 1, vector<int>(colLength + 1));
        //dp[i+1][j+1]表示以i,j作为右下角的最大的正方形大小
        int maxSquareEdge = 0;
        for (int i = 0; i < rowLength; i++)
            for (int j = 0; j < colLength; j++)
                maxSquareEdge = max(maxSquareEdge, dp[i + 1][j + 1] = matrix[i][j] == '0' ? 0 : min(min(dp[i + 1][j], dp[i][j + 1]), dp[i][j]) + 1);

        return maxSquareEdge*maxSquareEdge;
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
        auto matrix = getStringMatrix(str);
        auto inputMatrix = vector<vector<char>>();
        for (auto i : matrix)
        {
            auto temp = vector<char>();
            for (auto j : i)
            {
                temp.push_back(j.at(0));
            }
            inputMatrix.push_back(temp);
        }
        print(Solution().maximalSquare(inputMatrix));
    }
}
