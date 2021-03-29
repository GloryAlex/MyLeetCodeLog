#include "LeetCode.h"
using namespace std;

class Solution
{
    string s;
    string t;
    vector<vector<int>> dp;
    int getSame(int i, int j)
    {
        if (dp[i][j] != -1)
            return dp[i][j];

        int total = 0;
        for (int index = i; index < s.size(); index++)
        {
            if (s[index] == t[j])
                total += getSame(index + 1, j + 1);
        }
        return dp[i][j] = total;
    }

public:
    int numDistinct(string s, string t)
    {
        dp = vector<vector<int>>(s.size()+1, vector<int>(t.size() + 1, -1));
        for (int i = 0; i < dp.size(); i++)
            dp[i].back() = 1;

        this->s = s;
        this->t = t;
        return getSame(0, 0);
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string s, t;
        in >> s >> t;
        s = getString(s);
        t = getString(t);
        cout << Solution().numDistinct(s, t) << endl;
    }
}