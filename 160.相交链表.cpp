#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA,*b = headB;
        while(a!=b){
            a=(a?a->next:headB);
            b=(b?b->next:headA);
        }
        return a;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str, s2;
        in >> str >> s2;
        auto arr = getList(str);
        auto headB = getList(s2);
        print(Solution().getIntersectionNode(arr, headB));
    }
}