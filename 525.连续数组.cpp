#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=525 lang=cpp
 *
 * [525] 连续数组
 */

// @lc code=start
class Solution {
   public:
    int findMaxLength(vector<int>& nums) {
        int curDiff = 0;
        unordered_map<int, int> dict;
        dict[0] = -1;

        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            curDiff += nums[i] ? 1 : -1;
            if (dict.count(curDiff))
                result = max(result, i - dict[curDiff]);
            else
                dict[curDiff] = i;
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
        auto i = j.get<vector<int>>();
        print(Solution().findMaxLength(i));
    }
}