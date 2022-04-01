#include "lib/leetcode.h"
using namespace std;

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
// class Solution {
//    public:
//     /**
//      * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//      *
//      *
//      * @param head ListNode类
//      * @return ListNode类
//      */
//     ListNode* formatList(ListNode* head) {
//         ListNode* top = new ListNode(0);
//         ListNode* tail = top;
//         bool isHead = true;
//         while (head) {
//             auto next = head->next;
//             head->next=nullptr;
//             if(isHead){
//                 // 头插
//                 head->next=top->next;
//                 top->next=head;
//             }else{
//                 // 尾插
//                 while(tail->next){
//                     tail=tail->next;
//                 }
//                 tail->next=head;
//                 tail=head;
//             }
//             isHead = !isHead;
//             head = next;
//         }
//         return top->next;
//     }
// };

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        int k;
        in>>j>>k>>ws;
        auto arr = j.get<vector<int>>();
        cout<<Solution().ans(arr,k);
    }
}