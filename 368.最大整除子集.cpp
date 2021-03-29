#include "LeetCode.h"
using namespace std;

class Solution
{
private:
    struct Node
    {
        int val;
        int child;
    };
    void insertToTree(int val, vector<vector<Node>> &tree)
    {
        int index,i;
        for(index=(int)tree.size()-1;index>=0;index--){
            bool canInsert=false;
            for(i=0;i<tree[index].size();i++){
                if(val%tree[index][i].val==0){
                    canInsert=true;
                    break;
                }
            }
            if(canInsert)break;
        }
        //插入树
        index++;
        if(index==tree.size())tree.push_back({});
        tree[index].push_back({val,i});
    }

public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        if(nums.empty())return {};

        vector<vector<Node>> tree;
        sort(nums.begin(),nums.end());

        for(int i:nums)insertToTree(i,tree);

        int n=(int)tree.size()-1,index=0;
        vector<int> ret(n+1);
        while(n>=0){
            ret[n]=tree[n][index].val;
            index=tree[n][index].child;
            n--;
        }
        return ret;
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
        arr = Solution().largestDivisibleSubset(arr);
        print(arr);
    }
}