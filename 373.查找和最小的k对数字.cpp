#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    struct tuple
    {
        int a, b, c;

        bool operator<(const tuple& B)const
        {
            return a + b > B.a + B.b;
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int len1 = nums1.size(), len2 = nums2.size();
        if (!len1 || !len2)
            return {};
        if (len1 > len2)
            return kSmallestPairs(nums2, nums1, k);

        priority_queue<tuple, vector<tuple>> q;
        for (int i : nums1)
            q.push({i, nums2[0], 0});

        vector<vector<int>> ret;

        while (ret.size() < k && !q.empty())
        {
            auto cur = q.top();
            q.pop();

            ret.push_back({cur.a, cur.b});
            if (++cur.c < nums2.size())
                q.push({cur.a, nums2[cur.c], cur.c});
        }
        return ret;
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str1, str2;
        int k;
        in >> str1 >> str2 >> k;
        auto arr1 = getArray(str1);
        auto arr2 = getArray(str2);
        auto res = Solution().kSmallestPairs(arr1, arr2, k);
        print(res);
    }
}