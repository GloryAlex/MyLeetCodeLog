#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights, int k)
    {
        const int length = heights.size();
        vector<int> left(length);
        stack<int> s;
        //get left
        s = stack<int>();

        int top=-1;
        for (int i = 0; i < length; i++)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }
            // if(i>k)top=k-1;
            left[i] = s.empty() ? top : s.top();

            s.push(i);
        }
        //get right and res
        int ret = 0;
        s = stack<int>();

        top=length;
        for (int i = length - 1; i >= 0; i--)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }
            // if(i<k)top=k+1;
            int right = s.empty() ? top : s.top();

            if (right >= k && left[i] <= k)
            {
                ret = max(ret, (right - left[i] - 1) * heights[i]);
            }
            s.push(i);
        }

        return ret;
    }
    int maximumScore(vector<int> &nums, int k)
    {
        return largestRectangleArea(nums,k);
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
        int n;
        in >> n;
        cout << Solution().maximumScore(arr, n) << endl;
    }
}