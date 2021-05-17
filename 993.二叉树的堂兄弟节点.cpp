#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=993 lang=cpp
 *
 * [993] 二叉树的堂兄弟节点
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
   public:
    bool isCousins(TreeNode* root, int x, int y) {
        unordered_map<int, TreeNode*> father;
        unordered_map<int, int> depth;

        auto q = queue<TreeNode*>({root});
        int curDepth = 0;
        while (!q.empty()) {
            int count = q.size();
            while (count--) {
                auto node = q.front();
                q.pop();
                depth[node->val] = curDepth;
                if (node->left) {
                    q.push(node->left);
                    father[node->left->val] = node;
                }
                if (node->right) {
                    q.push(node->right);
                    father[node->right->val] = node;
                }
            }
            curDepth++;
        }
        return father[x] != father[y] && depth[x] == depth[y];
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        int x, y;
        in >> str >> x >> y;
        auto arr = deserialize(str);
        print(Solution().isCousins(arr, x, y));
    }
}