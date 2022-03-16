#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=421 lang=cpp
 *
 * [421] 数组中两个数的最大异或值
 */

// @lc code=start
class Solution {
   public:
    struct TrieNode {
        TrieNode* next[2] = {nullptr};

        void insert(int number) {
            auto root = this;
            for (int i = 31; i >= 0; i--) {
                auto bit = (number >> i) & 1;
                if (root->next[bit] == nullptr)
                    root->next[bit] = new TrieNode();
                root = root->next[bit];
            }
        }
        int maxXor(int number) {
            int ret = 0;
            auto root = this;
            for (int i = 31; i >= 0; i--) {
                ret <<= 1;
                auto bit = (number >> i) & 1;
                if (root->next[!bit]) {
                    ret |= 1;
                    root = root->next[!bit];
                } else {
                    root = root->next[bit];
                }
            }
            return ret;
        }
    };
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        int ret = 0;
        for (int i : nums) {
            root->insert(i);
            ret = max(ret, root->maxXor(i));
        }
        return ret;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = getArray(str);
        cout << Solution().findMaximumXOR(arr) << endl;
    }
}