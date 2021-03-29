#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    struct TreeNode
    {
        int minElement;
        TreeNode *zeroNext;
        TreeNode *oneNext;

        TreeNode(int _val) : minElement(_val), zeroNext(nullptr), oneNext(nullptr) {}
    };
    void insert(TreeNode *root, int num)
    {
        bitset<32> binary(num);
        for (int i = 31; i >= 0; i--)
        {
            int cur = binary[i];
            if (cur)
            {
                if (!root->oneNext)
                    root->oneNext = new TreeNode(num);
                root = root->oneNext;
            }
            else
            {
                if (!root->zeroNext)
                    root->zeroNext = new TreeNode(num);
                root = root->zeroNext;
            }
            root->minElement = min(root->minElement,num);
        }
    }
    int getMaxXor(TreeNode* root,int x,int floor){
        bitset<32> binary(x);
        int ret = 0;
        for(int i=31;i>=0;i--){
            ret <<= 1;
            if(binary[i]){
                if(root->zeroNext){
                    root=root->zeroNext;
                    ret |= 1;
                }else{
                    if(!root->oneNext || root->oneNext->minElement>floor)
                        return -1;
                    else root=root->oneNext;
                }
            }else{
                if(root->oneNext && root->oneNext->minElement<=floor){
                    root=root->oneNext;
                    ret |= 1;
                }else if(root->zeroNext){
                    root=root->zeroNext;
                }else return -1;
            }
        }
        return ret;
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        TreeNode* root = new TreeNode(INT_MIN);
        for(int i:nums)insert(root,i);

        vector<int> ret;
        for(auto query:queries){
            ret.push_back(getMaxXor(root,query[0],query[1]));
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
        in >> str;
        auto matrix = getMatrix(str);
        print(Solution().maximizeXor(arr, matrix));
    }
}