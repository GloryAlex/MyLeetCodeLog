#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=1984 lang=cpp
 *
 * [1984] 学生分数的最小差值
 */

// @lc code=start
class Solution {
   public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int result = INT_MAX;

        k = k - 1;
        for (int i = k; i < nums.size(); i++) {
            result = min(result, nums[i] - nums[i - k]);
        }
        return result;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    json j;
    int k;
    while (!in.eof()) {
        in >> j >> ws;
        in >> k;
        auto nums = j.get<vector<int>>();
        print(Solution().minimumDifference(nums, k));
    }
}