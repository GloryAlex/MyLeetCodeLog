#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        auto presum = nums;
        for (int i = 1; i < n; i++) {
            presum[i] += presum[i - 1];
        }
        int minLen = n + 1;
        for (int i = 0; i < n; i++) {
            int curTarget = target + (i == 0 ? 0 : presum[i - 1]);
            if (presum.back() < curTarget) continue;
            auto it = lower_bound(presum.begin() + i, presum.end(), curTarget);
            minLen = min(minLen, (int)(it - presum.begin()) - i + 1);
        }
        return minLen > n ? 0 : minLen / 2;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        int n;
        in >> n;
        json j;
        in >> j >> ws;
        auto arr = j.get<vector<int>>();
        print(Solution().minSubArrayLen(n, arr));
    }
}