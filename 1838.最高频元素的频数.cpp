#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=1838 lang=cpp
 *
 * [1838] 最高频元素的频数
 */

// @lc code=start
class Solution {
   public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long total = 0;
        int maxFreq     = 1;
        for (int l = 0, r = 1; r < nums.size(); r++) {
            total += (long long)(nums[r] - nums[r - 1]) * (r - l);
            while (total > k) {
                total -= nums[r] - nums[l];
                l++;
            }
            maxFreq = max(maxFreq, r - l + 1);
        }
        return maxFreq;
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
        print(Solution().maxFrequency(arr, k));
    }
}