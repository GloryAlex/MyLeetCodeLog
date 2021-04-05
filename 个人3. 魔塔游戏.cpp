#include "LeetCode.h"
using namespace std;

//WA: I don't know why
class Solution
{
    inline bool isValid(const vector<int>& nums){
        long long total = 0;
        for(int i:nums){
            total += i;
            if(total<0)return false;
        }
        return true;
    }
public:
    int magicTower(vector<int> &nums)
    {
        if(accumulate(nums.begin(),nums.end(),0)<0)return -1;
        auto f = [](const pair<int,int>& a,const pair<int,int>& b){return a.first>b.first;};

        auto q = priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(f)>(f);
        for(int i=0;i<nums.size();i++){
            q.push({nums[i],i});
        }

        for(int i=0;i<nums.size();i++){
            if(isValid(nums))return i;
            auto curMaxNode = q.top();q.pop();
            nums[curMaxNode.second]=0;
            nums.emplace_back(curMaxNode.first);
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
        cout << Solution().magicTower(arr)<<endl;
    }
}