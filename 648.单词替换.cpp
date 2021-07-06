#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=648 lang=cpp
 *
 * [648] 单词替换
 */

// @lc code=start
class Solution {
  class Trie {
    struct Node {
      bool isEnd = false;
      vector<Node*> next = vector<Node*>(26, nullptr);
    } root;
    public:
    void insert(const string& word) {
      auto node = &root;
      for (char i : word) {
        if (node->next[i - 'a'] == nullptr) {
          node->next[i - 'a'] = new Node;
        }
        node = node->next[i - 'a'];
      }
      node->isEnd = true;
    }
    string findRoot(const string& word){
        string result;
        auto node=&root;
        for(char i:word){
            if(node->next[i-'a']==nullptr)return word;
            node=node->next[i-'a'];
            result.push_back(i);
            if(node->isEnd)break;
        }
        return result;
    }
  };

 public:
  string replaceWords(vector<string>& dictionary, string sentence) {
      Trie tree = Trie();
      for(const auto& i:dictionary)tree.insert(i);
      auto ss = stringstream(sentence);
      auto result = string();
      while(!ss.eof()){
          string cur;
          ss>>cur;
          result.append(tree.findRoot(cur));
          result.push_back(' ');
      }
      result.pop_back();
      return result;
  }
};
// @lc code=end

int main() {
  ifstream in("input");
  while (!in.eof()) {
    string str, sentence;
    getline(in,str);
    getline(in,sentence);
    auto arr = getStringArray(str);
    sentence = getString(sentence);
    print(Solution().replaceWords(arr, sentence));
  }
}