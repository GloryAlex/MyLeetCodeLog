#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        typedef long long llong;
        set<llong> bucket;
        for(int i=0;i<nums.size();i++){
            llong num = static_cast<llong>(nums[i]);
            if(bucket.size()>k)bucket.erase(nums[i-k-1]);

            auto it = bucket.lower_bound(num-t);
            if(it!=bucket.end()&&*it<=num+t)return true;
            else bucket.insert(num);
        }
        return false;
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
        int k, t;
        in >> k >> t;
        print(Solution().containsNearbyAlmostDuplicate(arr, k, t));
    }
}