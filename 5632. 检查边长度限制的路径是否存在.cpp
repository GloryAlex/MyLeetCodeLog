#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList, vector<vector<int>> &queries)
    {
        //todo
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str, str2;
        int n;
        in >> n >> str >> str2;
        auto matrix = getMatrix(str);
        auto matrix2 = getMatrix(str2);
        auto res = Solution().distanceLimitedPathsExist(n,matrix,matrix2);
        print(res);
    }
}