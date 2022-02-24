#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */

// @lc code=start
class Solution {
   public:
    int maxProduct(vector<string>& words) {
        vector<int> masks(words.size());
        transform(words.begin(), words.end(), masks.begin(),
                  [&](const string& word) {
                      int res = 0;
                      for (char i : word) {
                          res |= (1 << (i - 'a' + 1));
                      }
                      return res;
                  });
        int result = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (masks[i] & masks[j])
                    continue;
                else
                    result = max(result,
                                 (int)words[i].size() * (int)words[j].size());
            }
        }
        return result;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto words = j.get<vector<string>>();
        cout << Solution().maxProduct(words) << endl;
    }
}