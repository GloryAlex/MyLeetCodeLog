#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    int purchasePlans(vector<int> &nums, int target)
    {
        sort(nums.begin(),nums.end());
        long long total=0;
        const int MOD=1e9+7;
        for(auto i=nums.begin();i!=nums.end();i++){
            if(*i*2>target)break;
            auto properPosisition = upper_bound(i,nums.end(),target-*i);
            if(properPosisition!=i)properPosisition--;

            total += (properPosisition-i); 
            total %= MOD;
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
        int target;
        in >> target;
        cout << Solution().purchasePlans(arr, target);
    }
}