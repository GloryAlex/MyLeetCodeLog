#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=720 lang=cpp
 *
 * [720] 词典中最长的单词
 */

// @lc code=start
class Solution {
   public:
    struct Node {
        bool isEnd = false;
        vector<Node*> next = vector<Node*>(26);
    };
    class Trie {
        Node dummy;
        Node* root = &dummy;

       public:
        void insert(string& word) {
            Node* node = root;
            for (char i : word) {
                if (node->next[i - 'a'] == NULL)
                    node->next[i - 'a'] = new Node();
                node = node->next[i - 'a'];
            }
            node->isEnd = true;
        }
        string getDepthWords() {
            queue<Node*> nodeQueue;
            queue<string> wordQueue;
            for (int i = 0; i < root->next.size(); i++) {
                if (root->next[i] != NULL && root->next[i]->isEnd) {
                    nodeQueue.push(root->next[i]);
                    wordQueue.push(string(1, i + 'a'));
                }
            }

            vector<string> temp;
            while (!nodeQueue.empty()) {
                int size = nodeQueue.size();
                temp.clear();
                while (size--) {
                    Node* node = nodeQueue.front();
                    nodeQueue.pop();
                    string cur = wordQueue.front();
                    wordQueue.pop();
                    temp.push_back(cur);

                    for (int i = 0; i < node->next.size(); i++) {
                        if (node->next[i] != NULL && node->next[i]->isEnd) {
                            nodeQueue.push(node->next[i]);
                            char tempChar = i + 'a';
                            wordQueue.push(cur + tempChar);
                        }
                    }
                }
            }

            auto ret = min_element(temp.begin(),temp.end());
            return ret==temp.end()?"":*ret;
        }
    };
    string longestWord(vector<string>& words) {
        Trie trie = Trie();
        for (string& word : words) {
            trie.insert(word);
        }
        return trie.getDepthWords();
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = getStringArray(str);
        print(Solution().longestWord(arr));
    }
}