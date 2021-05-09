#include "LeetCode.h"
using namespace std;

class Solution
{
    const int MOD = 1e9 + 7;

public:
    int maxSumMinProduct(vector<int> &nums)
    {
        int length = nums.size();
        vector<int> preSum = vector<int>(length + 1);
        vector<int> nextLess = vector<int>(length);
        vector<int> preLess = vector<int>(length);
        for (int i = 0; i < length; i++)
        {
            preSum[i + 1] = preSum[i] + nums[i];
        }

        stack<int> order = stack<int>();
        for (int i = length - 1; i >= 0; i--)
        {
            while (!order.empty() && nums[order.top()] >= nums[i])
                order.pop();
            nextLess[i] = order.empty() ? length : order.top();
            order.push(i);
        }

        order = stack<int>();
        for (int i = 0; i < length; i++)
        {
            while (!order.empty() && nums[order.top()] >= nums[i])
                order.pop();
            preLess[i] = order.empty() ? -1 : order.top();
            order.push(i);
        }
        long long ret = 0;
        for (int i = 0; i < length; i++)
        {
            long long cur = nums[i];
            long long disSum = preSum[nextLess[i]] - preSum[preLess[i]+1];
            ret = max(disSum * cur, ret);
        }
        return ret % MOD;
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
        cout << Solution().maxSumMinProduct(arr) << endl;
    }
}