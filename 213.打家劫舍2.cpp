#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums, int begin, int end)
    {
        int preMax = 0, curMax = 0;
        for (int i = begin, len = nums.size(); i != end; i = (i + 1) % len)
        {
            int temp = curMax;
            curMax = max(curMax, nums[i] + preMax);
            preMax = temp;
        }
        return max(curMax, preMax);
    }
    int rob(vector<int> &nums)
    {
        return max(rob(nums,0,(int)nums.size()-1),rob(nums,1,0));
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
        cout << Solution().rob(arr) << endl;
    }
}