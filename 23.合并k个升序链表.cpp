#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    ListNode *mergeList(ListNode* h1,ListNode* h2){
        auto dummy = ListNode(0);
        auto node = &dummy;
        while(h1&&h2){
            if(h1->val<h2->val){
                node->next=h1;
                h1=h1->next;
            }else{
                node->next=h2;
                h2=h2->next;
            }
            node=node->next;
        }
        node->next=h1?h1:h2;
        return dummy.next;
    }
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        auto comparator = [&](ListNode* a,ListNode* b){return a->val>b->val;};
        auto q = priority_queue<ListNode*,vector<ListNode*>,decltype(comparator)>(comparator);
        auto dummy = ListNode(0);
        auto node = &dummy;
        
        for(auto i:lists)
        if(i)q.push(i);
        
        while(!q.empty()){
            auto cur = q.top();
            q.pop();
            node->next=cur;
            node=node->next;

            if(cur->next)q.push(cur->next);
        }
        return dummy.next;
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
        auto arr = getMatrix(str);
        vector<ListNode*> lists;
        for(auto i:arr){
            lists.push_back(getList(to_string(i)));
        }
        print(Solution().mergeKLists(lists));
    }
}