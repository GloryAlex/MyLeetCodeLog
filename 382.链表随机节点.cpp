#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=382 lang=cpp
 *
 * [382] 链表随机节点
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
    ListNode* head;

   public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least
       one node. */
    Solution(ListNode* head) { this->head = head; }

    /** Returns a random node's value. */
    int getRandom() {
        ListNode* node = head;

        int ret = -1;
        int k = 1;
        while (node) {
            int random = rand();
            if (random % k == 0) ret = node->val;
            k++;
            node = node->next;
        }
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        int n;
        in >> str >> n;
        auto arr = getList(str);
        auto s = Solution(arr);
        for (int i = 0; i < n; i++)
            cout << s.getRandom() << (i == n-1 ? "\n" : ",");
    }
}