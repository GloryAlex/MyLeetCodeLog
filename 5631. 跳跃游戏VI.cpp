#include "LeetCode.h"
#include <set>
using namespace std;

class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        if(nums.empty())return 0;
        int length = nums.size();
        vector<int> dp(length);

        set<int> q;
        dp[0]=nums[0];
        q.insert(nums[0]);

        for(int i=1;i<length;i++){
            dp[i] = *q.rbegin()+nums[i];

            q.insert(dp[i]);
            if(q.size()>k)q.erase(dp[i-k]);
        }

        return dp.back();
    }
};


int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        int k;
        in >> str >> k;
        auto arr = getArray(str);
        int ans = Solution().maxResult(arr, k);
        print(ans);
    }
}