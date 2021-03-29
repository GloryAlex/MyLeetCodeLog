#include "LeetCode.h"
using namespace std;

class Solution
{
    int getMaxXor(vector<int>::iterator begin,vector<int>::iterator end,int x){
        int ret=-1;
        while(begin!=end){
            ret = max(ret,(*begin++)^x);
        }
        return ret;
    }
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        sort(nums.begin(),nums.end());
        vector<int> ret;
        for(auto& query:queries){
            int x=query[0],m=query[1];
            auto index = upper_bound(nums.begin(),nums.end(),m);

            ret.push_back(getMaxXor(nums.begin(),index,x));
        }
        return ret;
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str, str2;
        in >> str >> str2;
        auto arr = getArray(str);
        auto qu = getMatrix(str2);
        print(Solution().maximizeXor(arr, qu));
    }
}