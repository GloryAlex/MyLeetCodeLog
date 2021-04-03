#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int length = height.size();
        //求出每个点左边绝对高于自己的方块和右边绝对高于自己的方块
        vector<int> left = vector<int>(length),
                    right = vector<int>(length);
        stack<int> monoStack = stack<int>();
        //求左边的情况
        for (int i = 1, maxIndex = 0; i < length; i++)
        {
            if (height[i] >= height[maxIndex])
                maxIndex = i;
            left[i] = maxIndex;
        }
        //求右边的情况
        for (int i = length - 2, maxIndex = length - 1; i >= 0; i--)
        {
            if (height[i] >= height[maxIndex])
                maxIndex = i;
            right[i] = maxIndex;
        }
        //遍历并汇总答案
        int total = 0;
        for (int i = 1; i < length - 1; i++)
        {
            total += min(height[left[i]], height[right[i]]) - height[i];
        }
        return total;
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
        print(Solution().trap(arr));
    }
}