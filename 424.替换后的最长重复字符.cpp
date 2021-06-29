#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=424 lang=cpp
 *
 * [424] 替换后的最长重复字符
 */

// @lc code=start
class Solution {
  struct Node {
    char c = '\0';
    int num = 0;
    Node* next = nullptr;
    Node* prev = nullptr;
    Node* detach() {
      Node* prevNode = prev;
      prev->next = next;
      next->prev = prev;
      return this;
    }
    void insertBefore(Node* node) {
      this->prev = node->prev;
      this->next = node;

      node->prev->next = this;
      node->prev = this;
    }
    void insertAfter(Node* node) {
      this->prev = node;
      this->next = node->next;

      node->next->prev = this;
      node->next = this;
    }
  };
  class Dictionary {
    vector<Node*> dict;
    Node _head, _tail, *head, *tail;

   public:
    Dictionary() {
      dict = vector<Node*>(26, nullptr);
      head = &_head;
      tail = &_tail;
      head->next = tail;
      tail->prev = head;
    }
    void inc(char letter) {
      int pos = letter - 'A';
      if (dict[pos] == nullptr) {
        dict[pos] = new Node{letter, 0, nullptr, nullptr};
        dict[pos]->insertBefore(tail);
      }
      dict[pos]->num++;
      while (dict[pos]->prev != head && dict[pos]->num > dict[pos]->prev->num) {
        //前移一位
        dict[pos] = dict[pos]->detach();
        dict[pos]->insertBefore(dict[pos]->prev);
      }
    }
    void dec(char letter) {
      int pos = letter - 'A';
      dict[pos]->num--;
      while (dict[pos]->next != tail && dict[pos]->num < dict[pos]->next->num) {
        //后移一位
        dict[pos] = dict[pos]->detach();
        dict[pos]->insertAfter(dict[pos]->next);
      }
    }
    int getMaxFreq() { return head->next->num; }
  };

 public:
  int characterReplacement(string s, int k) {
    int maxLength = 0;
    Dictionary d;
    for (int i = 0, j = 0; i < s.size() && j < s.size(); i++) {
      while (j < s.size() && j - i - d.getMaxFreq() <= k) {
        d.inc(s[j++]);
        if (j - i - d.getMaxFreq() > k) break;
        maxLength = max(maxLength, j - i);
      }
      d.dec(s[i]);
    }
    return maxLength;
  }
};
// @lc code=end

int main() {
  ifstream in("input");
  while (!in.eof()) {
    string str;
    int k;
    in >> str >> k;
    str = getString(str);
    print(Solution().characterReplacement(str, k));
  }
}