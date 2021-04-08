#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        const int MAX = amount + 1;
        sort(coins.begin(), coins.end());
        vector<int> dp = vector<int>(amount + 1, MAX);
        dp[0] = 0;
        for (int i = 1; i < MAX; i++)
        {
            for (int coin : coins)
            {
                if (coin > i)
                    break;
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        return dp[amount]==MAX?-1:dp[amount];
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        in >> str;
        auto arr = getArray(str);
        int k;
        in >> k;
        cout << Solution().coinChange(arr, k) << endl;
    }
}