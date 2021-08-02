#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=987 lang=cpp
 *
 * [987] 二叉树的垂序遍历
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<TreeNode*>> cols;
        unordered_map<TreeNode*, int> rowOf;
        function<void(TreeNode*, int, int)> dfs;
        dfs = [&](TreeNode* node, int row, int col) -> void {
            if (!node) return;
            cols[col].push_back(node);
            rowOf[node] = row;
            dfs(node->left, row + 1, col - 1);
            dfs(node->right, row + 1, col + 1);
        };
        auto cmp = [&](TreeNode* a, TreeNode* b) {
            if (rowOf[a] != rowOf[b])
                return rowOf[a] < rowOf[b];
            else
                return a->val < b->val;
        };
        auto toArray = [](vector<vector<TreeNode*>> nodes) {
            vector<vector<int>> result;
            for (auto& node : nodes) {
                result.push_back(vector<int>());
                for (auto& i : node) result.back().push_back(i->val);
            }
            return result;
        };
        dfs(root, 0, 0);
        vector<vector<TreeNode*>> allNodes;
        for (auto& col : cols) allNodes.push_back(col.second);
        for (auto& nodes : allNodes) sort(nodes.begin(), nodes.end(), cmp);
        return toArray(allNodes);
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto tree = deserialize(str);
        print(Solution().verticalTraversal(tree));
    }
}