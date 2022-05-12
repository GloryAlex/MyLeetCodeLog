#include "lib/leetcode.h"
using namespace std;

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
   public:
    bool isSubTree(TreeNode* b, TreeNode* a) {
        if (a == nullptr) return true;
        if (b == nullptr) return false;

        return (a->val == b->val && isSubTree(b->left, a->left) &&
                isSubTree(b->right, a->right));
    }
    bool isSubStructure(TreeNode* b, TreeNode* a) {
        if (a == nullptr) return false;
        queue<TreeNode*> q({b});
        while (!q.empty()) {
            auto i = q.front();
            q.pop();
            if (isSubTree(i, a)) return true;

            if (i->left) q.push(i->left);
            if (i->right) q.push(i->right);
        }
        return false;
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string a, b;
        in >> a >> b >> ws;
        auto at = deserialize(a);
        auto bt = deserialize(b);
        print(Solution().isSubStructure(at, bt));
    }
}