#include "LeetCode.h"
#include <list>

using namespace std;

class LFUCache {
public:
    struct Node {
        int key = 0;
        int value = 0;
        int frequency = 1;
        Node *next = nullptr;
        Node *prev = nullptr;
    };

    class MyList {
    private:
        int size = 0;
        Node *head = new Node();
        Node *tail = new Node();
    public:
        MyList() {
            head->next = tail;
            tail->prev = head;
        }

        ~MyList() {
            while (head) {
                Node *cur = head;
                head = head->next;
                delete cur;
            }
        }

        Node *removeLast() {
            if (this->size != 0)return remove(tail->prev);
            else return nullptr;
        }

        Node *remove(Node *node) {
            node->next->prev = node->prev;
            node->prev->next = node->next;
            node->prev = node->next = nullptr;

            size--;
            return node;
        }

        Node *enqueue(Node *node) {
            node->prev = head;
            node->next = head->next;

            node->prev->next = node;
            node->next->prev = node;

            size++;
            return node;
        }

        Node *peek() {
            return size == 0 ? nullptr : head->next;
        }

        bool isEmpty(){
            return !size;
        }
    };

private:
    unordered_map<int, MyList> freqDictionary;
    unordered_map<int, Node *> keyDictionary;
    int minFrequency = 1;
    int capacity = 0;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if(keyDictionary.count(key)){
            auto node = keyDictionary[key];
            update(node->key,node->value);
            return node->value;
        }
        else return -1;
    }

    void put(int key, int value) {
        if(capacity==0)return;
        if(keyDictionary.count(key)){
            //只更新不插入
            update(key,value);
            return;
        }
        if(keyDictionary.size()==capacity){
            //容量已满时先删除结点
            auto node = freqDictionary[minFrequency].removeLast();
            keyDictionary.erase(node->key);
            delete node;
            if(freqDictionary[minFrequency].isEmpty())freqDictionary.erase(minFrequency);
        }
        //然后再插入结点
        minFrequency=1;
        auto node = freqDictionary[minFrequency].enqueue(new Node{key,value,minFrequency});
        keyDictionary[key]=node;
    }

private:
    void update(int key,int value){
        Node * node = keyDictionary[key];
        //更新结点的值
        int curFrequency = node->frequency++;
        node->value=value;
        //从当前频率队列移除结点并加入新的频率队列
        node = freqDictionary[curFrequency].remove(node);
        freqDictionary[node->frequency].enqueue(node);
        //更新频率队列
        if(freqDictionary[curFrequency].isEmpty()){
            freqDictionary.erase(curFrequency);
            if(minFrequency==curFrequency)minFrequency++;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main() {
    int n;
    cin >> n;
    LFUCache cache = LFUCache(n);
    while (true) {
        string str;
        cin >> str;
        if (str == "put") {
            int a, b;
            cin >> a >> b;
            cache.put(a, b);
        } else if (str == "get") {
            int c;
            cin >> c;
            cout << cache.get(c) << endl;
        } else
            return 0;
    }
}