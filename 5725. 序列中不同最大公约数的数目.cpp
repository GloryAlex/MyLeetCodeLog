#include "LeetCode.h"
using namespace std;

class Solution
{
    inline int gcd(int a,int b) {
        if(!a||!b)return 0;
        while(b^=a^=b^=a%=b);
        return a;
    }
    public:
    int countDifferentSubsequenceGCDs(vector<int> &nums)
    {
        //TODO
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
        cout << Solution().countDifferentSubsequenceGCDs(arr)<<endl;
    }
}