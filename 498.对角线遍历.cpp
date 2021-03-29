#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &matrix)
    {
        if (matrix.empty())
            return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> res;
        for (int i = 0; i < n; i++)
        {
            res.push_back({});
            for (int j = 0; j <= i && j < m; j++)
            {
                res.back().push_back(matrix[j][i - j]);
            }
        }

        for (int j = 1; j < m; j++)
        {
            res.push_back({});
            for (int i = 0; i + j < m && i < n; i++)
            {
                res.back().push_back(matrix[j + i][n - i - 1]);
            }
        }

        vector<int> ans;
        for (int i = 0; i < res.size(); i++)
        {
            if (i % 2 == 0)
            {
                ans.insert(ans.end(), res[i].rbegin(), res[i].rend());
            }
            else
            {
                ans.insert(ans.end(), res[i].begin(), res[i].end());
            }
        }
        return ans;
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        in >> str;
        auto arr = getMatrix(str);
        print(Solution().findDiagonalOrder(arr));
    }
}