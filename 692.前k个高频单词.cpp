#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=692 lang=cpp
 *
 * [692] 前K个高频单词
 */

// @lc code=start
class Solution {
   public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> dict;
        for (const auto& word : words) dict[word]++;

        auto f = [&](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second != b.second ? a.second > b.second
                                        : a.first < b.first;
        };
        auto q = priority_queue<pair<string, int>, vector<pair<string, int>>,
                                decltype(f)>(f);

        for (auto& i : dict) {
            q.push(i);
            if (q.size() > k) q.pop();
        }

        auto ret = vector<string>(q.size());
        auto i = ret.rbegin();
        while (!q.empty()) {
            *i++ = q.top().first;
            q.pop();
        }
        return ret;
    }
};
// @lc code=end
int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        int k;
        in >> str >> k;
        auto arr = getStringArray(str);
        print(Solution().topKFrequent(arr, k));
    }
}
