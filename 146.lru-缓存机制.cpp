#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
class LRUCache {
    class LinkedList {
       public:
        struct Node {
            int key = 0;
            int val = 0;
            Node* next = nullptr;
            Node* prev = nullptr;
        };

       private:
        Node *head, *tail;

       public:
        LinkedList() {
            head = new Node();
            tail = new Node();
            head->next = tail;
            tail->prev = head;
        }
        ~LinkedList() {
            while (head) {
                auto temp = head;
                head = head->next;
                delete temp;
            }
        }

        Node* detach(Node* node) {
            node->next->prev = node->prev;
            node->prev->next = node->next;

            node->prev = node->next = nullptr;
            return node;
        }
        Node* add(int key, int value) { return add(new Node{key, value}); }
        Node* add(Node* node) {
            node->next = head->next;
            node->prev = head;

            head->next->prev = node;
            head->next = node;

            return node;
        }

        Node* getHead() { return head; }
        Node* getTail() { return tail; }
    } list;
    unordered_map<int, LinkedList::Node*> dict;
    int capacity = 0;

   public:
    LRUCache(int capacity) { this->capacity = capacity; }

    int get(int key) {
        if (!dict.count(key)) return -1;

        put(key, dict[key]->val);
        return dict[key]->val;
    }

    void put(int key, int value) {
        if (dict.count(key)) {
            auto node = list.detach(dict[key]);
            list.add(node)->val = value;
            return;
        }

        if (dict.size() >= capacity) {
            auto last = list.detach(list.getTail()->prev);
            dict.erase(last->key);
            delete last;
        }

        dict[key] = list.add(key, value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto op = j.get<vector<string>>();
        in >> j >> ws;
        auto args = j.get<vector<vector<int>>>();

        LRUCache l = LRUCache(args[0][0]);
        for (int i = 1; i < op.size(); i++) {
            if (op[i] == "get")
                print(l.get(args[i][0]), ",");
            else {
                l.put(args[i][0], args[i][1]);
                cout << "null,";
            }
        }

        cout << endl;
    }
}