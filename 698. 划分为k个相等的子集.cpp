#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        //预处理，求出平均值，并判断最大值是否大于平均值
        int target=0,maxElement=nums[0];
        for(int i:nums){
            target+=i;
            maxElement=max(maxElement,i);
        }
        if(target%k)return false;
        target/=k;
        if(maxElement>target)return false;
        //递归求解答案
        // vector<int> hasVisit = vector<int>(nums.size());
        //TODO
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
        print(Solution().canPartitionKSubsets(arr, k));
    }
}