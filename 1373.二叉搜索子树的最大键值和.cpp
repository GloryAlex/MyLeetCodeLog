#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=1373 lang=cpp
 *
 * [1373] 二叉搜索子树的最大键值和
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    struct returnVal{
        bool isBst;
        int maxValue;
        int minValue;
        int sum;
    };
    int maxSum;
    returnVal findMaxBST(TreeNode* root){
        if(!root)return {true,INT_MIN,INT_MAX,0};
        auto left = findMaxBST(root->left);
        auto right=findMaxBST(root->right);

        if(left.isBst&&right.isBst
        && left.maxValue<root->val&&right.minValue>root->val){
            int curSum = left.sum+right.sum+root->val;
            maxSum=max(maxSum,curSum);
            return {true,max(root->val,right.maxValue),min(root->val,left.minValue),curSum};
        }
        return {false,INT_MIN,INT_MAX,0};
    }
   public:
    int maxSumBST(TreeNode* root) {
        maxSum=0;
        findMaxBST(root);
        return maxSum;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = deserialize(str);
    }
}