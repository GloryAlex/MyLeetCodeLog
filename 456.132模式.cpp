#include "LeetCode.h"
#include <set>
using namespace std;

class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        int length = nums.size();
        if(length<3)return false;

        //find the pattern of '132'
        int maxOf2 = INT_MIN;
        stack<int> candidateOf2 = stack<int>();
        
        candidateOf2.push(nums.back());
        for(int i=length-2;i>=0;i--){
            //judge if nums[i] can be 1
            if(nums[i]<maxOf2)return true;
            //judge if nums[i] can be 3
            while(!candidateOf2.empty() && candidateOf2.top()<nums[i]){
                maxOf2=max(maxOf2,candidateOf2.top());
                candidateOf2.pop();
            }
            if(nums[i] > maxOf2)
            candidateOf2.push(nums[i]);
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
        cout << to_string(Solution().find132pattern(arr)) << endl;
    }
}