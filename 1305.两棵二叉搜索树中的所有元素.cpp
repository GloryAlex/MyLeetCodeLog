#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=1305 lang=cpp
 *
 * [1305] 两棵二叉搜索树中的所有元素
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        stack<TreeNode*> s1, s2;
        while (root1) {
            s1.push(root1);
            root1 = root1->left;
        }
        while (root2) {
            s2.push(root2);
            root2 = root2->left;
        }

        while (!s1.empty() || !s2.empty()) {
            if (!s1.empty() && (s2.empty() || s1.top()->val < s2.top()->val)) {
                auto node1 = s1.top();
                s1.pop();
                res.push_back(node1->val);
                node1 = node1->right;
                while (node1) {
                    s1.push(node1);
                    node1 = node1->left;
                }
            } else {
                auto node2 = s2.top();
                s2.pop();
                res.push_back(node2->val);
                node2 = node2->right;
                while (node2) {
                    s2.push(node2);
                    node2 = node2->left;
                }
            }
        }
        return res;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string s;
        in >> s >> ws;
        auto tree1 = deserialize(s);
        in >> s >> ws;
        auto tree2 = deserialize(s);
        print(Solution().getAllElements(tree1, tree2));
    }
}