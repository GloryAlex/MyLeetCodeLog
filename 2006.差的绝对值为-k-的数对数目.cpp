#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=2006 lang=cpp
 *
 * [2006] 差的绝对值为 K 的数对数目
 */

// @lc code=start
class Solution {
   public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> values;
        for (int i : nums) {
            values[i] = values.count(i) ? values[i] + 1 : 1;
        }
        int result = 0;
        for (auto [i, _] : values) {
            if (values.count(i + k)) result += values[i] * values[i + k];
        }
        return result;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    json j;
    while (!in.eof()) {
        in >> j >> ws;
        int k;
        in >> k;
        auto arr = j.get<vector<int>>();
        print(Solution().countKDifference(arr, k));
    }
}