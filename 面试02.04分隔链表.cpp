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
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode dummyHead = ListNode(0);
        dummyHead.next=head;
        while(head && head->next){
            if(head->next->val<x){
                auto cur = head->next;
                head->next=head->next->next;

                cur->next=dummyHead.next;
                dummyHead.next=cur;
            }
            else head=head->next;
        }
        return dummyHead.next;
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        in >> str;
        auto l = getList(str);
        int x;
        in >> x;
        print(Solution().partition(l, x));
    }
}