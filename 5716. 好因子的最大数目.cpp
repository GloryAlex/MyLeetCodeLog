#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    int maxNiceDivisors(long long primeFactors)
    {
        if(primeFactors<4)return primeFactors;
        typedef long long llong;
        const llong MOD = 1e9 + 7;
        llong curMax = primeFactors - 1;
        
        

        return curMax % MOD;
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        int str;
        in >> str;
        cout << Solution().maxNiceDivisors(str) << endl;
    }
}