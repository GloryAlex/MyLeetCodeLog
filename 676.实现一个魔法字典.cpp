#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=676 lang=cpp
 *
 * [676] 实现一个魔法字典
 */

// @lc code=start
class MagicDictionary {
    struct Node {
        bool isEnd = false;
        unordered_map<char, Node*> next;

        void add(string::iterator begin, string::iterator end) {
            auto node = this;
            for (auto it = begin; it < end; it++) {
                auto i = *it;
                if (node->next.count(i) == false) node->next[i] = new Node();
                node = node->next[i];
            }
            node->isEnd = true;
        }
        bool search(string::iterator begin, string::iterator end) {
            auto node = this;
            for (auto it = begin; it < end; it++) {
                auto i = *it;
                if (node->next.count(i) == false) return false;
                node = node->next[i];
            }
            return node->isEnd;
        }
    };
    Node* root;

   public:
    MagicDictionary() { root = new Node(); }

    void buildDict(vector<string> dictionary) {
        for (auto& word : dictionary) root->add(word.begin(),word.end());
    }

    bool search(string searchWord) { 
        auto node = root; 
        for(auto i=searchWord.begin(),end=searchWord.end();i!=end;i++){
            // 搜索
            for(auto [c,n]:node->next){
                if(c!=*i && n->search(i+1,end))return true;
            }
            // 不行则进入下一层
            if(!node->next.count(*i))break;
            node=node->next[*i];
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto ops = j.get<vector<string>>();
        in >> j >> ws;
        auto args = j.get<vector<vector<string>>>();
        auto m = MagicDictionary();
        for (int i = 1; i < ops.size(); i++) {
            if (ops[i] == "search")
                print(m.search(args[i][0]));
            else
                m.buildDict(args[i]);
        }
    }
}