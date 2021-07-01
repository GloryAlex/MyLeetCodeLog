#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 */

// @lc code=start
class Solution {
   public:
    //约束
    // 1 <= nums.length <= 2 * 104
    // -109 <= nums[i] <= 109
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> dict;
        for (int i : nums) {
            dict[i]++;
        }
        int maxLength = 0;
        for (const auto& [num, freq] : dict) {
            if (dict.count(num + 1)) {
                maxLength = max(maxLength, freq + dict[num + 1]);
            }
        }
        return maxLength;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = getArray(str);
        print(Solution().findLHS(arr));
    }
}