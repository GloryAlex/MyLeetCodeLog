#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    struct TreeNode
    {
        bool val;
        TreeNode *zeroNext;
        TreeNode *oneNext;

        TreeNode(int _val) : val(_val), zeroNext(nullptr), oneNext(nullptr) {}
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
                    root->oneNext = new TreeNode(1);
                root = root->oneNext;
            }
            else
            {
                if (!root->zeroNext)
                    root->zeroNext = new TreeNode(0);
                root = root->zeroNext;
            }
        }
    }
    int getMaxXOR(TreeNode *root, int num)
    {
        bitset<32> binary(num);
        int ret = 0;
        for (int i = 31; i >= 0; i--)
        {
            ret <<= 1;
            int cur = binary[i];
            if (cur)
            {
                if (root->zeroNext)
                {
                    ret |= 1;
                    root = root->zeroNext;
                }
                else
                    root = root->oneNext;
            }
            else
            {
                if (root->oneNext)
                {
                    ret |= 1;
                    root = root->oneNext;
                }
                else
                    root = root->zeroNext;
            }
        }
        return ret;
    }

    void deleteTree(TreeNode *node)
    {
        if (node)
        {
            if (node->oneNext)
                deleteTree(node->oneNext);
            if (node->zeroNext)
                deleteTree(node->zeroNext);
            deleteTree(node);
        }
    }
    int findMaximumXOR(vector<int> &nums)
    {
        TreeNode* root=new TreeNode(0);
        for(int i:nums)insert(root,i);
        int ret = 0;
        for(int i:nums)ret=max(ret,getMaxXOR(root,i));
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
        cout << Solution().findMaximumXOR(arr)<<endl;
    }
}