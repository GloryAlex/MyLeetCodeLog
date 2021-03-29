#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    int maxRotateFunction(vector<int> &a)
    {
        int sum = 0, n = a.size();
        long long tempMaxSum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += a[i];
            tempMaxSum += a[i] * i;
        }

        int maxSum = tempMaxSum;
        for (int i = 1; i < n; i++)
        {
            tempMaxSum = tempMaxSum+sum-n*a[n-i];
            maxSum = max(tempMaxSum,(long long)maxSum);
        }
        return maxSum;
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
        cout << Solution().maxRotateFunction(arr);
    }
}