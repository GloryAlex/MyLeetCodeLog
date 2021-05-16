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
   struct TrieNode{
       bool isEnd;//只有1和0
       TrieNode* oneNext = nullptr;
       TrieNode* zeroNext = nullptr;
   };
   void insert(TrieNode* root,int number){
       auto binary = bitset<32>(number);
       for(int i=31;i>=0;i--){
           int cur = binary[i];
           if(cur){
               if(root->oneNext==nullptr)root->oneNext=new TrieNode();
                root=root->oneNext;
           }else{
               if(root->zeroNext=nullptr)root->zeroNext=new TrieNode();
               root=root->zeroNext;
           }
       }
   }
   int getMaxXor(TrieNode* root,int number){
       auto binary = bitset<32>(number);
       //TODO: 完成异或函数的编写
   }
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        for(int i:nums)insert(root,i);
        int ret=0;
        for(int i:nums)ret=max(ret,getMaxXor(root,i));
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