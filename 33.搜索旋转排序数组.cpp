#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = (int)nums.size() - 1;
        while (left <= right)
        {
            int mid = left+(right-left)/2;
            if(nums[mid]==target)return mid;

            if(nums[left]<=nums[mid]){
                if(nums[left]<=target && target<=nums[mid])right=mid-1;
                else left=mid+1;
            }else{
                if(nums[right]>=target && target>=nums[mid])left=mid+1;
                else right=mid-1;
            }
        }
        return -1;
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
        int t;
        in >> t;
        cout << Solution().search(arr, t);
    }
}