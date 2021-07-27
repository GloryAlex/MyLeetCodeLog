#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
   public:
    int findSecondMinimumValue(TreeNode* root) {
        auto q = queue<TreeNode*>({root});
        long long min=INT_MAX+1LL,secondMin=INT_MAX+1LL;
        while (!q.empty())
        {
            auto cur=q.front();
            q.pop();
            if(cur->val<=min){
                min=cur->val;
            }else if(cur->val<=secondMin){
                secondMin=cur->val;
            }
            if(cur->left&&cur->right){
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return secondMin==INT_MAX+1LL?-1:secondMin;
        
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto tree = deserialize(str);
        print(Solution().findSecondMinimumValue(tree));
    }
}