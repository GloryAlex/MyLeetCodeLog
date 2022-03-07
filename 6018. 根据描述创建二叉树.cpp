#include "lib/leetcode.h"
using namespace std;

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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> dict;
        unordered_set<TreeNode*> hasFather;
        for (const auto d : descriptions) {
            int val = d[0], child = d[1], isLeft = d[2];
            if (!dict.count(val)) dict[val] = new TreeNode(val);
            if (!dict.count(child)) dict[child] = new TreeNode(child);
            if (isLeft)
                dict[val]->left = dict[child];
            else
                dict[val]->right = dict[child];

            hasFather.insert(dict[child]);
        }
        for (auto [_, node] : dict) {
            if (!hasFather.count(node)) return node;
        }
        return nullptr;
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto arr = j.get<vector<vector<int>>>();
        print(Solution().createBinaryTree(arr));
    }
}