#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
   public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        unordered_map<char, int> dict;

        auto l = s.begin(), r = s.begin();
        string res = "";
        for (char i : t) dict[i]--;
        for (; r < s.end(); r++) {
            dict[*r]++;
            if (containsAll(dict)) {
                do {
                    dict[*l++]--;
                } while (containsAll(dict));
                dict[*--l]++;
                if (res.empty() || r - l + 1 < res.size()) res = string(l, r+1);
            }
        }
        return res;
    }
    bool containsAll(unordered_map<char, int>& dict) {
        for (const auto& [_, v] : dict) {
            if (v < 0) return false;
        }
        return true;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j, k;
        in >> j >> k >> ws;
        print(Solution().minWindow(j.get<string>(), k.get<string>()));
    }
}