#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=863 lang=cpp
 *
 * [863] 二叉树中所有距离为 K 的结点
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    unordered_map<TreeNode*, TreeNode*> father;
    void findFather(TreeNode* node) {
        if (!node) return;
        if (node->left) {
            father[node->left] = node;
            findFather(node->left);
        }
        if (node->right) {
            father[node->right] = node;
            findFather(node->right);
        }
    }
    void dfs(TreeNode* node, TreeNode* from, int depth, const int target, vector<int>& result) {
        if (!node) return;
        if (depth == target) {
            result.emplace_back(node->val);
            return;
        }
        if (node->left != from) dfs(node->left, node, depth + 1, target, result);
        if (node->right != from) dfs(node->right, node, depth + 1, target, result);
        if (father[node] != from) dfs(father[node], node, depth + 1, target, result);
    }

   public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        father.clear();
        findFather(root);
        vector<int> result = vector<int>();
        dfs(target, NULL, 0, k, result);
        return result;
    }
};
// @lc code=end

TreeNode* find(TreeNode* node, int target) {
    if (!node) return NULL;
    if (node->val == target) return node;
    auto l = find(node->left, target);
    if (l)
        return l;
    else
        return find(node->right, target);
}

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        int target, k;
        in >> str >> target >> k;
        auto node       = deserialize(str);
        auto targetNode = find(node, target);
        print(Solution().distanceK(node, targetNode, k));
    }
}