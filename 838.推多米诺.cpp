#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=838 lang=cpp
 *
 * [838] 推多米诺
 */

// @lc code=start
class Solution {
   public:
    string pushDominoes(string dominoes) {
        vector<int> allDominoes = vector<int>(dominoes.size());
        const int LEFT = -1, RIGHT = 1, STAND = 0;
        transform(dominoes.begin(), dominoes.end(), allDominoes.begin(),
                  [=](char i) {
                      if (i == 'L')
                          return LEFT;
                      else if (i == 'R')
                          return RIGHT;
                      else
                          return STAND;
                  });
        vector<int> hasVisit = vector<int>(dominoes.size(), false);
        queue<int> q;
        for (int i = 0; i < allDominoes.size(); i++) {
            if (allDominoes[i]) q.push(i);
        }
        while (!q.empty()) {
            int size = q.size();
            queue needVisit=q;
            while(!needVisit.empty()){
                hasVisit[needVisit.front()]=true;
                needVisit.pop();
            }
            while (size--) {
                int i = q.front();
                q.pop();
                if (allDominoes[i] == LEFT && i > 0 &&
                    hasVisit[i - 1] == false) {
                    allDominoes[i - 1] += LEFT;
                    q.push(i - 1);
                } else if (allDominoes[i] == RIGHT &&
                           i < (int)allDominoes.size() - 1 &&
                           hasVisit[i + 1] == false) {
                    allDominoes[i + 1] += RIGHT;
                    q.push(i + 1);
                }
            }
        }
        transform(allDominoes.begin(), allDominoes.end(), dominoes.begin(),
                  [=](int i) {
                      if (i == LEFT)
                          return 'L';
                      else if (i == RIGHT)
                          return 'R';
                      else
                          return '.';
                  });
        return dominoes;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str >> ws;
        print(Solution().pushDominoes(str));
    }
}