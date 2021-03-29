#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        const int length = heights.size();
        vector<int> left(length);
        stack<int> s;
        //get left
        s = stack<int>();
        for (int i = 0; i < length; i++)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();

            s.push(i);
        }
        //get right and res
        int ret = 0;
        s = stack<int>();
        for (int i = length - 1; i >= 0; i--)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }
            int right = s.empty() ? length : s.top();

            ret = max(ret, (right - left[i] - 1) * heights[i]);
            s.push(i);
        }

        return ret;
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
        cout << Solution().largestRectangleArea(arr) << endl;
    }
}