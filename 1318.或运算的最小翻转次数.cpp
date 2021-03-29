#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    int minFlips(int a, int b, int c)
    {
        int countFlips = 0;
        for (; a != c || b != c; a >>= 1, b >>= 1, c >>= 1)
            countFlips += (c & 1) ? (!(a & 1) && !(b & 1)) : ((a & 1) + (b & 1));

        return countFlips;
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        int a, b, c;
        in >> a >> b >> c;
        cout << Solution().minFlips(a, b, c) << endl;
    }
}