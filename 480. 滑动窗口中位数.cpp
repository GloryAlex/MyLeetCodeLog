#include "LeetCode.h"
#include <set>
using namespace std;

class Solution
{
public:
    double getMid(const multiset<int> &window, int k)
    {
        auto mid = window.begin();
        advance(mid, k / 2);

        double cur = (double)*mid;
        if (k % 2 == 0)
        {
            cur = (cur + (double)*prev(mid, 1)) / 2;
        }
        return cur;
    }
    vector<double> medianSlidingWindow(vector<int> &nums, int k)
    {
        multiset<int> window;
        vector<double> ret;
        for (int i = 0; i < k; i++)
            window.insert(nums[i]);
        for (int i = k; i < nums.size(); i++)
        {
            ret.push_back(getMid(window, k));

            window.erase( window.find(nums[i - k]));
            window.insert(nums[i]);
        }

        ret.push_back(getMid(window, k));
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
        int k;
        in >> k;
        print(Solution().medianSlidingWindow(arr, k));
    }
}