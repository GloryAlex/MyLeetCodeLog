#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        return conjoinPairs(nums, 0, (int)nums.size() - 1);
    }
    int conjoinPairs(vector<int> &nums, int begin, int end)
    {
        if (end == begin)
            return 0;
        int mid = begin + (end - begin) / 2;
        int left = conjoinPairs(nums, begin, mid);
        int right = conjoinPairs(nums, mid + 1, end);

        //开始归并，并统计右边数字小于左边数字的总和
        int total = 0;
        vector<int> temp = vector<int>(end - begin + 1);
        temp.clear();

        int i = begin, j = mid + 1;
        while (i <= mid && j <= end)
        {
            if (nums[i] < nums[j])
                temp.push_back(nums[i++]);
            else
            {
                temp.push_back(nums[j++]);
                total+=mid-i+1;
            }
        }
        while (i <= mid)
            temp.push_back(nums[i++]);
        while (j <= end)
            temp.push_back(nums[j++]);

        //合并至主数组
        i = 0;
        while (begin <= end)
            nums[begin++] = temp[i++];

        return total + left + right;
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
        cout << Solution().reversePairs(arr) << endl;
    }
}