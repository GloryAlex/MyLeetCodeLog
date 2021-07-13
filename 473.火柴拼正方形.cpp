#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=473 lang=cpp
 *
 * [473] 火柴拼正方形
 */

// @lc code=start
class Solution {
    bool dfs(vector<int>& buckets, vector<int>::iterator cur, vector<int>::iterator end, int target) {
        if (cur == end) {
            for (int i : buckets)
                if (i != target) return false;
            return true;
        }
        for (int& i : buckets) {
            if (i + *cur <= target) {
                i += *cur;
                if (dfs(buckets, cur + 1, end, target)) return true;
                i -= *cur;
            }
            if (i == 0 || i + *cur == target) break;
        }
        return false;
    }

   public:
    bool makesquare(vector<int>& matchsticks) {
        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (total % 4) return false;
        vector<int> temp(4);
        return dfs(temp, matchsticks.begin(), matchsticks.end(), total / 4);
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = getArray(str);
        print(Solution().makesquare(arr));
    }
}