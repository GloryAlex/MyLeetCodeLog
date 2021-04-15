#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int preMax=0,curMax=0;
        for(int i=0;i<nums.size();i++){
            int temp=curMax;
            curMax = max(curMax,nums[i]+preMax);
            preMax=temp;
        }
        return max(curMax,preMax);
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
        cout << Solution().rob(arr) << endl;
    }
}