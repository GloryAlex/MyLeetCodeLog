#include "LeetCode.h"
using namespace std;

class Solution
{
    const int MOD = 1e9 + 7;

public:
    int waysToSplit(vector<int> &nums)
    {
        const int length = nums.size();

        vector<int> prex(length);
        prex[0] = nums[0];
        for (int i = 1; i < length; i++)
            prex[i] = prex[i - 1] + nums[i];

        long long total = 0;
        for (int i = 0; i < length - 1 && 3 * prex[i] <= prex.back(); i++)
        {
            //寻找左右边界
            //左边界：中和大于等于左和
            int left = i + 1, right = length - 1;
            int leftTarget = 2 * prex[i];
            while (left <= right)
            {
                int mid = (right + left) / 2;
                if (prex[mid] < leftTarget)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            int leftEdge = right + 1;
            //右边界：右和大于等于中和
            left = i + 1, right = length - 2;

            int rightTarget = (prex.back() + prex[i]) / 2;
            while (left <= right)
            {
                int mid = (left + right) / 2;
                if (prex[mid] <= rightTarget)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            int rightEdge = left - 1;

            total += rightEdge - leftEdge + 1;
        }
        return total % MOD;
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
        cout << Solution().waysToSplit(arr) << endl;
    }
}