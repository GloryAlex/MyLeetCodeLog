#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    int checkRecord(int n)
    {
        const int MOD = 1e9 + 7;

        for(int i=4;i<=n;i++){
            possible[i]=((2*possible[i-1])%MOD+MOD-possible[i-4])%MOD;
        }
        long long res = possible[n];
        for(int i=1;i<=n;i++){
            res += (possible[i-1]*possible[n-i])%MOD;
        }
        return res%MOD;
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        int n;
        in >> n;
        cout << Solution().checkRecord(n) << endl;
    }
}