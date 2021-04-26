#include "LeetCode.h"
using namespace std;

class Solution
{
    struct MyList{
        ListNode head;
        ListNode* tail;

        MyList(){
            head = ListNode(0);
            tail=&head;
        };
        void insert(int val){
            ListNode* node = new ListNode(val);
            tail->next=node;
            tail=node;
        }
        ListNode* getList(){
            return head.next;
        }
    };
    void dfs(TreeNode *node, int depth, vector<ListNode *>& nodes)
    {
        if (!node)
            return;
        //插入对应深度的链表
        //TOOD
        dfs(node->left, depth + 1, nodes);
        dfs(node->right, depth + 1, nodes);
    }

public:
    vector<ListNode *> listOfDepth(TreeNode *tree)
    {
        vector<ListNode *> nodes;
        dfs(tree, 0, nodes);
        return nodes;
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        in >> str;
        auto arr = deserialize(str);
        print(Solution().listOfDepth(arr));
    }
}