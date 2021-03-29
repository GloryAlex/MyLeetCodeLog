#include "LeetCode.h"
using namespace std;

class Solution
{
private:
    const int MOD = 1337;

public:
    int quickPow(int a, int b)
    {
        int ret = 1;
        while (b)
        {
            if (b & 1)
                ret = (ret * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return ret;
    }
    int superPow(int a, vector<int> &b)
    {
        if (b.empty())
            return 1;
        a %= MOD;
        int cur = b.back();
        b.pop_back();

        return ((quickPow(a, cur)) * (quickPow(superPow(a, b), 10))) % MOD;
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        int n;
        string str;
        in >> n >> str;
        auto arr = getArray(str);
        print(Solution().superPow(n, arr));
    }
}