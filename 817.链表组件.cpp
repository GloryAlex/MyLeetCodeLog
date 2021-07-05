#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=817 lang=cpp
 *
 * [817] 链表组件
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  int numComponents(ListNode* head, vector<int>& nums) {
      auto dict = unordered_set<int>(nums.begin(),nums.end());
      auto node = head;
      int count = 0;
      bool isConnected = false;
      while(node){
          if(!dict.count(node->val))isConnected=false;
          else{
              if(!isConnected){
                  isConnected=true;
                  count++;
              }
          }
          node=node->next;
      }
      return count;
  }
};
// @lc code=end

int main() {
  ifstream in("input");
  while (!in.eof()) {
    string s1, s2;
    in >> s1 >> s2;
    auto head = getList(s1);
    auto arr = getArray(s2);
    print(Solution().numComponents(head, arr));
  }
}