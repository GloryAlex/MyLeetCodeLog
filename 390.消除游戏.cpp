#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    int lastRemaining(int n)
    {
        return n == 1 ? n : 2 * (n / 2 + 1 - lastRemaining(n / 2));
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        int num;
        in >> num;
        cout << Solution().lastRemaining(num) << endl;
    }
}