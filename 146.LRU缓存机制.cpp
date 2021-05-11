#include "LeetCode.h"
using namespace std;

class LRUCache
{
public:
    struct Node
    {
        int key = -1;
        int val = -1;
        Node *next = nullptr;
        Node *prev = nullptr;
    };

private:
    unordered_map<int, Node *> dict;
    Node head;
    Node tail;
    int capacity;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head.next = &tail;
        tail.prev = &head;
    }

    int get(int key)
    {
        if (dict.count(key))
            return update(key)->val;
        else
            return -1;
    }

    void put(int key, int value)
    {
        if (dict.count(key)) //更新结点位置
            update(key, value);
        else //插入结点
            insert(key, value);
    }
    Node *update(int key, int value)
    {
        Node *node = update(key);
        node->val = value;
        return node;
    }
    Node *update(int key)
    {
        Node *node = dict[key];
        if (node == head.next)
            return node;

        node->prev->next = node->next;
        node->next->prev = node->prev;

        node->next = head.next;
        head.next->prev = node;
        node->prev = &head;
        head.next = node;

        return node;
    }
    void insert(int key, int val)
    {
        if (dict.size() == capacity)
            removeLast();
        Node *node = new Node{key, val, head.next, &head};

        head.next->prev = node;
        head.next = node;
        dict[key] = node;
    }
    void removeLast()
    {
        Node *node = tail.prev;
        tail.prev = node->prev;
        node->prev->next = &tail;

        dict.erase(node->key);
        delete node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    int n;
    cin >> n;
    LRUCache cache(n);
    string op;
    while (cin >> op)
    {
        if (op == "put")
        {
            int a, b;
            cin >> a >> b;
            cache.put(a, b);
        }
        else if (op == "get")
        {
            int c;
            cin >> c;
            cout << cache.get(c) << endl;
        }
        else
            return 0;
        cout << "请输入下一条指令" << endl;
    }
}