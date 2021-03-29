#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        unordered_set<int> cur;
        int credit = 0;
        int ans = 0;
        int i=0,j=0,length=nums.size();

        while(i<length&&j<length){
            while(j<length && !cur.count(nums[j])){
                cur.insert(nums[j]);
                credit += nums[j];
                j++;
            }
            ans = max(credit,ans);
            if(j==length)break;
            
            int doubleNumber=nums[j];
            while(i<j && doubleNumber!=nums[i]){
                cur.erase(nums[i]);
                credit-=nums[i];
                i++;
            }

            cur.erase(nums[i]);
            credit-=nums[i];
            i++;
        }
        return max(ans,credit);
    }
};

int main()
{
    
}