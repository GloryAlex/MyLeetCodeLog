#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = static_cast<int>(matrix.size()) - 1;
        //先沿副对角线翻转
        for (int i = 0, end = n; i <= n; i++, end--)
            for (int j = 0; j < end; j++)
                swap(matrix[i][j], matrix[n - j][n - i]);
        //再每列翻转
        for (int i = 0, mid = (n + 1) / 2; i < mid; i++)
            for (int j = 0; j <= n; j++)
                swap(matrix[i][j], matrix[n - i][j]);
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        in >> str;
        auto matrix = getMatrix(str);
        Solution().rotate(matrix);
        print(matrix);
    }
}