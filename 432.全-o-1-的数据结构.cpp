// 请你实现一个数据结构支持以下操作：

// - Inc(key) - 插入一个新的值为 1 的 key。或者使一个存在的 key 增加一，保证 key
// 不为空字符串。
// - Dec(key) - 如果这个 key 的值是
// 1，那么把他从数据结构中移除掉。否则使一个存在的 key 值减一。如果这个 key
// 不存在，这个函数不做任何事情。key 保证不为空字符串。
// - GetMaxKey() - 返回 key
// 中值最大的任意一个。如果没有元素存在，返回一个空字符串"" 。
// - GetMinKey() - 返回 key
// 中值最小的任意一个。如果没有元素存在，返回一个空字符串""。
#include "LeetCode.h"
using namespace std;

/*
 * @lc app=leetcode.cn id=432 lang=cpp
 *
 * [432] 全 O(1) 的数据结构
 */

// @lc code=start
class AllOne {
  struct Node {
    string key;
    int val = 0;
    Node* prev = nullptr;
    Node* next = nullptr;
  };
  Node _dummy_head, _dummy_tail;
  //必要的基本成员
  unordered_map<string, Node*> dict;
  Node* head = &_dummy_head;  //最小值结点的前一个
  Node* tail = &_dummy_tail;  //最大值结点的后一个

 public:
  /** Initialize your data structure here. */
  AllOne() {
    head->next = tail;
    tail->prev = head;
  }
  bool isEmpty() { return head->next == tail && tail->prev == head; }
  void moveFront(Node* node) {
    //值变小
    if (node->prev == head) return;
    node->prev->next = node->next;
    node->next->prev = node->prev;

    node->next = node->prev;
    node->prev = node->prev->prev;

    node->prev->next = node;
    node->next->prev = node;
  }
  void moveBack(Node* node) {
    //值变大
    if (node->next == tail) return;
    node->prev->next = node->next;
    node->next->prev = node->prev;

    node->prev = node->next;
    node->next = node->next->next;

    node->prev->next = node;
    node->next->prev = node;
  }
  /** Inserts a new key <Key> with value 1. Or increments an existing key by 1.
   */
  void inc(string key) {
    if (!dict.count(key)) {
      dict[key] = new Node{key, 0, head, head->next};
      head->next->prev = dict[key];
      head->next = dict[key];
    }
    auto node = dict[key];
    node->val++;
    while (node->next != tail && node->val > node->next->val) moveBack(node);
  }

  /** Decrements an existing key by 1. If Key's value is 1, remove it from the
   * data structure. */
  void dec(string key) {
    if (!dict.count(key)) return;
    auto node = dict[key];
    node->val--;
    while (node->prev != head && node->val < node->prev->val) moveFront(node);
    if (!isEmpty() && head->next->val == 0) {
      auto node = head->next;
      head->next = head->next->next;
      dict.erase(node->key);
      //ATTENTION: memory leak!
      // delete node;
    }
  }

  /** Returns one of the keys with maximal value. */
  string getMaxKey() { return tail->prev->key; }

  /** Returns one of the keys with Minimal value. */
  string getMinKey() { return head->next->key; }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end

int main() {
  ifstream in("input");
  while (!in.eof()) {
    string op, para;
    in >> op >> para;
    auto ops = getStringArray(op);
    auto temp = getStringMatrix(para);
    vector<string> paras;
    for (auto i : temp) {
      if (i.size())
        paras.push_back(i[0]);
      else
        paras.push_back("");
    }

    auto a = AllOne();
    for (int i = 1; i < ops.size(); i++) {
      if (ops[i] == "inc")
        a.inc(paras[i]);
      else if (ops[i] == "getMaxKey")
        cout << a.getMaxKey() << " ";
      else if (ops[i] == "dec")
        a.dec(paras[i]);
      else if (ops[i] == "getMinKey")
        cout << a.getMinKey() << " ";
    }
    cout<<endl;
  }
}
