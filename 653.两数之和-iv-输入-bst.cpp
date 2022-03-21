#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
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
    struct TreeIterator {
        stack<TreeNode*> stk;

       public:
        TreeIterator(TreeNode* node) {
            while (node) {
                stk.push(node);
                node = node->left;
            }
        }
        bool hasNext() { return !stk.empty(); }
        int val() { return stk.top()->val; }
        int next() {
            auto node = stk.top();
            stk.pop();
            int val = node->val;

            node = node->right;
            while (node) {
                stk.push(node);
                node = node->left;
            }

            return val;
        }
    };
    struct TreeReverseIterator {
        stack<TreeNode*> stk;

       public:
        TreeReverseIterator(TreeNode* node) {
            while (node) {
                stk.push(node);
                node = node->right;
            }
        }
        bool hasNext() { return !stk.empty(); }
        int val() { return stk.top()->val; }
        int next() {
            auto node = stk.top();
            stk.pop();
            int val = node->val;

            node = node->left;
            while (node) {
                stk.push(node);
                node = node->right;
            }

            return val;
        }
    };

   public:
    bool findTarget(TreeNode* root, int k) {
        auto l = TreeIterator(root);
        auto r = TreeReverseIterator(root);
        while(l.stk.top()!=r.stk.top()){
            if(l.val()+r.val()>k){
                r.next();
            }else if(l.val()+r.val()<k){
                l.next();
            }else{
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string s;
        int k;
        in >> s >> k >> ws;
        auto t = deserialize(s);
        print(Solution().findTarget(t, k));
    }
}