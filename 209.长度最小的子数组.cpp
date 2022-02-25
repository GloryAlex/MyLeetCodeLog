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
        int end = 0;
        int curSum = 0;
        int result = INT_MAX;
        for (; end < nums.size() && curSum + nums[end] < target; end++) {
            curSum += nums[end];
        }
        int begin = 0;
        for (; end < nums.size(); end++) {
            curSum += nums[end];

            while (begin < end && curSum - nums[begin] >= target) {
                curSum -= nums[begin];
                begin++;
            }

            result = min(result, end - begin + 1);
        }
        return result == INT_MAX ? 0 : result;
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