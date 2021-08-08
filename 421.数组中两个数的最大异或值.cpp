#include "LeetCode.h"
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
        TrieNode* one = nullptr;
        TrieNode* zero = nullptr;
        ~TrieNode(){
            if(one)delete one;
            if(zero)delete zero;
        }
    };
    void insert(TrieNode* root, int number) {
        auto binary = bitset<32>(number);
        for (int i = 31; i >= 0; i--) {
            int cur = binary[i];
            if (cur) {
                if (root->one == nullptr) root->one = new TrieNode();
                root = root->one;
            } else {
                if (root->zero == nullptr) root->zero = new TrieNode();
                root = root->zero;
            }
        }
    }
    int getMaxXor(TrieNode* root, int number) {
        bitset<32> binary(number);
        int ret = 0;
        for (int i = 31; i >= 0; i--) {
            ret <<= 1;
            if (binary[i]) {
                if (root->zero) {
                    ret |= 0x1;
                    root = root->zero;
                } else {
                    root = root->one;
                }
            } else {
                if (root->one) {
                    ret |= 0x1;
                    root = root->one;
                } else {
                    root = root->zero;
                }
            }
        }
        return ret;
    }
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        for (int i : nums) insert(root, i);
        int ret = 0;
        for (int i : nums) ret = max(ret, getMaxXor(root, i));
        delete root;
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