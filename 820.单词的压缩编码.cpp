#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=820 lang=cpp
 *
 * [820] 单词的压缩编码
 */

// @lc code=start
class Solution {
    class Trie {
        struct Node {
            unordered_map<char, Node*> children;
            bool isEnd = false;
        } * root;

       public:
        Trie() { root = new Node(); }
        void add(string word) {
            auto node = root;
            for (auto it = word.rbegin(); it != word.rend(); it++) {
                auto i = *it;
                if (node->children.count(i) == false)
                    node->children[i] = new Node();
                node = node->children[i];
            }
            node->isEnd = true;
        }
        vector<int> sumAllLeaves() { 
            vector<int> total; 
            auto q = queue<Node*>({root});
            for(int level=0;!q.empty();level++){
                int size=q.size();
                while(size--){
                    auto node=q.front();
                    q.pop();
                    if(node->children.empty()){
                        total.push_back(level);
                    }else{
                        for(auto [_,child]:node->children)q.push(child);
                    }
                }
            }
            return total;
        }
    };

   public:
    int minimumLengthEncoding(vector<string>& words) {
        Trie tree;
        for(auto& i:words)tree.add(i);
        auto res = tree.sumAllLeaves();
        return accumulate(res.begin(),res.end(),res.size());
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto words = j.get<vector<string>>();
        print(Solution().minimumLengthEncoding(words));
    }
}