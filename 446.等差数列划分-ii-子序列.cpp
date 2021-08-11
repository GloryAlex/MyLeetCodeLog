#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=446 lang=cpp
 *
 * [446] 等差数列划分 II - 子序列
 */

// @lc code=start
class Solution {
   public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        using llong = long long;
        int length  = nums.size();
        llong ret   = 0;
        auto dp     = vector<unordered_map<long long, int>>(length);
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < i; j++) {
                auto diff = (long long)nums[i] - nums[j];
                auto cnt  = dp[j].count(diff) ? dp[j][diff] : 0;
                ret += cnt;
                dp[i][diff] += cnt + 1;
            }
        }
        return ret;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = getArray(str);
        print(Solution().numberOfArithmeticSlices(arr));
    }
}