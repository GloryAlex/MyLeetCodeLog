#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=698 lang=cpp
 *
 * [698] 划分为k个相等的子集
 */

// @lc code=start
class Solution {
   public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        int avg = sum / k;
        sort(nums.begin(), nums.end(), greater<int>());
        auto hasVisit = vector<int>(nums.size());
        return dfs(nums, avg, 0, 0, k, hasVisit);
    }
    bool dfs(vector<int>& nums, int target, int index, int curSum, int remain,
             vector<int>& hasVisit) {
        if (remain == 0) return true;
        if (curSum == target)
            return dfs(nums, target, 0, 0, remain - 1, hasVisit);

        for (int i = index; i < nums.size(); i++) {
            if (nums[i] + curSum > target) continue;
            if (hasVisit[i] ||
                (i > 0 && nums[i - 1] == nums[i] && !hasVisit[i - 1]))
                continue;
            hasVisit[i] = true;
            if (dfs(nums, target,index+1, curSum + nums[i], remain, hasVisit))
                return true;
            hasVisit[i] = false;
        }
        return false;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        int k;
        in >> str >> k;
        auto arr = getArray(str);
        print(Solution().canPartitionKSubsets(arr, k));
    }
}