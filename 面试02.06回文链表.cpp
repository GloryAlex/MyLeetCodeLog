#include "LeetCode.h"
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
    ListNode *reverseList(ListNode *node)
    {
        ListNode dummy(0);
        dummy.next = node;

        while (node && node->next)
        {
            auto cur = node->next;
            node->next = cur->next;

            cur->next = dummy.next;
            dummy.next = cur;
        }
        if (node)
            node->next = NULL;
        return dummy.next;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        if (!head)
            return true;
        // return reverseList(head);
        ListNode *fast = head, *slow = head;
        while (fast && slow)
        {
            fast = fast->next;
            if (fast)
                fast = fast->next;
            else
                break;
            slow = slow->next;
        }
        //从slow开始反转链表
        auto afterHalf = slow->next;
        slow->next = NULL;
        afterHalf = reverseList(afterHalf);
        //比较是否相同
        auto begin = head, post = afterHalf;
        bool flag = true;
        while (begin && post && flag)
        {
            if (begin->val != post->val)
                flag = false;
        }
        //恢复链表
        afterHalf = reverseList(afterHalf);
        slow->next = afterHalf;
        //返回结果
        return flag;
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        in >> str;
        auto arr = getList(str);
        print(Solution().isPalindrome(arr));
    }
}