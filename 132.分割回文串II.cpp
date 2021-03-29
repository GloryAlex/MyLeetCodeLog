#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    int minCut(string s)
    {
        int n = s.size();
        auto isPalidrome = vector<vector<int>>(n, vector<int>(n, true));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                isPalidrome[i][j] = (s[i] == s[j] && isPalidrome[i + 1][j - 1]);
            }
        }

        auto lessPartition = vector<int>(n, INT_MAX);
        for (int i = 0; i < n; i++)
        {
            if (isPalidrome[0][i])
                lessPartition[i] = 0;
            else
            {
                for (int j = 0; j < i; j++)
                {
                    if (isPalidrome[j+1][i])
                        lessPartition[i] = min(lessPartition[i], lessPartition[j] + 1);
                }
            }
        }
        return lessPartition.back();
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        in >> str;
        if (str.size() && str[0] == '"')
            str = str.substr(1, str.size() - 2);
        cout << Solution().minCut(str) << endl;
    }
}