#include "lib/leetcode.h"
using namespace std;

/*
 * @lc app=leetcode.cn id=1405 lang=cpp
 *
 * [1405] 最长快乐字符串
 */

// @lc code=start
class Solution {
    bool isPossible(string str, char last) {
        if (str.size() <
        
         2)
            return true;
        else
            return str.back() != last || str[str.size() - 2] != last;
    }

   public:
    string longestDiverseString(int a, int b, int c) {
        string result;
        unordered_map<char, int> dict = {{'a', a}, {'b', b}, {'c', c}};
        vector<char> order = {'a', 'b', 'c'};
        auto cmp = [&](char i, char j) { return dict[i] > dict[j]; };
        while (1) {
            sort(order.begin(), order.end(), cmp);
            bool doneInsert = false;
            for (char i : order) {
                if (dict[i] && isPossible(result, i)) {
                    result.push_back(i);
                    dict[i]--;
                    doneInsert = true;
                    break;
                }
            }
            if (!doneInsert) break;
        }
        return result;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        int a, b, c;
        in >> a >> b >> c;
        cout << Solution().longestDiverseString(a, b, c) << endl;
    }
}