#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
class Solution
{
    ListNode *reverseList(ListNode *head)
    {
        if(head==NULL)return head;

        auto dummy = ListNode(0);
        dummy.next = head;
        auto node = head->next;
        head->next = NULL;
        while (node)
        {
            auto next = node->next;
            node->next = dummy.next;
            dummy.next = node;
            node = next;
        }
        return dummy.next;
    }
public:
    void reorderList(ListNode *head)
    {
        auto dummy = ListNode(0);
        dummy.next = head;
        auto fast = &dummy, slow = &dummy;
        while (fast->next && slow->next)
        {
            fast = fast->next;
            slow = slow->next;
            if (fast->next)
                fast = fast->next;
        }
        auto rightNode = reverseList(slow->next);
        auto leftNode = dummy.next;
        auto node = &dummy;
        slow->next = NULL;

        while (rightNode && leftNode)
        {
            node->next = leftNode;
            leftNode = leftNode->next;
            node = node->next;
            node->next = rightNode;
            rightNode = rightNode->next;
            node = node->next;
        }

        node->next = (rightNode ? rightNode : leftNode);
    }
};
// @lc code=end

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        in >> str;
        auto node = getList(str);
        Solution().reorderList(node);
        print(node);
    }
}