#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */

// @lc code=start
class Solution {
    struct TrieNode {
        bool isEnd = false;
        vector<TrieNode*> children = vector<TrieNode*>(26, nullptr);
        TrieNode*& next(char i) { return children[i - 'a']; }
        bool isEmpty() {
            for (auto i : children)
                if (i) return false;
            return true;
        }
        void remove(char i) {
            delete children[i - 'a'];
            children[i - 'a'] = nullptr;
        }
    } root;
    TrieNode* find(const string& word) {
        auto node = &root;
        for (char i : word) {
            if (!node->next(i))
                return node->next(i);
            else
                node = node->next(i);
        }
        return node;
    }
    void add(const string& word) {
        auto node = &root;
        for (char i : word) {
            if (!node->next(i)) {
                node->next(i) = new TrieNode();
            }
            node = node->next(i);
        }
        node->isEnd = true;
    }

   public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        if (board.empty()) return {};
        int m = board.size(), n = board[0].size();
        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        auto isValid = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n && board[x][y] != '#';
        };

        for (auto& word : words) {
            add(word);
        }

        vector<string> res;
        string tempWord;
        auto dfs = function<void(int, int, TrieNode*)>();
        dfs = [&](int i, int j, TrieNode* node) {
            char cellar = board[i][j];
            tempWord.push_back(cellar);

            auto nextNode = node->next(cellar);
            if (!nextNode) {
                tempWord.pop_back();
                return;
            }
            if (nextNode->isEnd){
                 res.emplace_back(tempWord);
                 nextNode->isEnd=false;
            }

            board[i][j] = '#';
            for (auto [x_offset, y_offset] : directions) {
                int x = i + x_offset, y = j + y_offset;
                if (isValid(x, y)) {
                    dfs(x, y, nextNode);
                }
            }
            board[i][j] = tempWord.back();
            tempWord.pop_back();

            if (nextNode->isEmpty()) {
                node->remove(cellar);
            }
        };
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) dfs(i, j, &root);

        return res;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto board = j.get<vector<vector<string>>>();
        auto charBoard = vector<vector<char>>();
        for (int i = 0; i < board.size(); i++) {
            auto temp = vector<char>(board[i].size());
            for (int j = 0; j < board[i].size(); j++) {
                temp[j] = board[i][j][0];
            }
            charBoard.push_back(temp);
        }
        in >> j >> ws;
        auto words = j.get<vector<string>>();
        print(Solution().findWords(charBoard, words));
    }
}