#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        //virtual head node
        auto dummy = ListNode(0);
        dummy.next=head;
        //start checking
        ListNode* node = &dummy;
        while(node->next){
            if(node->next->val==val){
                auto temp = node->next;
                node->next=node->next->next;
                delete temp;
            }
            else node=node->next;
        }
        return dummy.next;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        int k;
        in >> str >> k;
        auto arr = getList(str);
        print(Solution().removeElements(arr, k));
    }
}