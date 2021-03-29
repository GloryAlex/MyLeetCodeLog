#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return n;

        int up = 1, down = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
            {
                //呈上升趋势
                if (down < up + 1)
                    down = up + 1;
            }
            else if (nums[i] < nums[i - 1])
            {
                //呈下降趋势
                if (up < down + 1)
                    up = down + 1;
            }
            else
            {
                //什么也不做
            }
        }
        return max(up, down);
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        in >> str;
        auto num = getArray(str);
        print(Solution().wiggleMaxLength(num));
    }
}