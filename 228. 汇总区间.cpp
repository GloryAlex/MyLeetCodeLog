#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    class range
    {
        int left, right;

    public:
        range(int _val)
        {
            left = right = _val;
        }
        range(int _left, int _right)
        {
            left = _left;
            right = _right;
        }
        int getLeft(void)
        {
            return left;
        }
        int getRight(void)
        {
            return right;
        }
        bool update(int newRight)
        {
            if (newRight == right + 1)
            {
                right = newRight;
                return true;
            }
            else
            {
                return false;
            }
        }
        string toString(void)
        {
            if (left == right)
                return to_string(left);
            else
                return to_string(left) + "->" + to_string(right);
        }
    };
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ret;
        if (nums.empty())
            return ret;

        range r(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            if (!r.update(nums[i]))
            {
                ret.push_back(r.toString());
                r = range(nums[i]);
            }
        }

        ret.push_back(r.toString());
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
        print(Solution().summaryRanges(arr));
    }
}