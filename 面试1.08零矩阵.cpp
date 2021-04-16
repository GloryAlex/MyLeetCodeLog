#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        if (matrix.empty())
            return;
        int m = matrix.size(), n = matrix[0].size();

        int firstRow = 1;
        int firstCol = 1;
        //扫描第一行与第一列
        for (int i = 0; i < m; i++)
            if (!matrix[i][0])
            {
                firstRow = 0;
                break;
            }
        for (int j = 0; j < n; j++)
            if (!matrix[0][j])
            {
                firstCol = 0;
                break;
            }
        //扫描每行与每列
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (!matrix[i][j])
                    matrix[0][j] = matrix[i][0] = 0;
        //执行清零操作
        for (int i = 1; i < m; i++)
            if (!matrix[i][0])
                for (int j = 0; j < n; j++)
                    matrix[i][j] = 0;
        for (int j = 1; j < n; j++)
            if (!matrix[0][j])
                for (int i = 0; i < m; i++)
                    matrix[i][j] = 0;
        //处理第一行和第一列
        if (!firstRow)
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
        if (!firstCol)
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;
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
        Solution().setZeroes(matrix);
        print(matrix);
    }
}