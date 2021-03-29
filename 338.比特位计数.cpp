#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> bitCount = vector<int>(num + 1);
        int curMax = 0;
        for (int i = 1, len = 1, j = 0; i <= num; i = j + 1, len <<= 1)
        {
            for (j = i; j <= num; j++)
            {
                bitCount[j] = bitCount[j - len] + 1;

                if (bitCount[j] > curMax)
                {
                    curMax = bitCount[j];
                    i = j + 1;
                    break;
                }
            }
        }
        return bitCount;
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        int n;
        in >> n;
        print(Solution().countBits(n));
    }
}