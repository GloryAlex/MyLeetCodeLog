#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=1818 lang=cpp
 *
 * [1818] 绝对差值和
 */

// @lc code=start
class Solution {
   public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        const int MOD = 1e9 + 7;
        using llong   = long long;
        llong sum       = 0;
        for (int i = 0; i < nums1.size(); i++)
            sum += abs(nums1[i] - nums2[i]);
        llong minSum = sum;
        auto tree  = set<int>(nums1.begin(), nums1.end());

        for (int i = 0; i < nums1.size(); i++) {
            int target  = nums2[i];
            int curDiff = abs(nums1[i] - target);
            int newDiff = curDiff;
            auto it     = tree.upper_bound(target);
            if (it != tree.end()) {
                newDiff = min(newDiff, abs(*it - target));
            }
            if (it != tree.begin()) {
                it--;
                newDiff = min(newDiff, abs(*it - target));
            }
            //更新最小差值和
            minSum = min(minSum, sum - curDiff + newDiff);
        }
        return minSum % MOD;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = getArray(str);
        in >> str;
        auto arr2 = getArray(str);
        print(Solution().minAbsoluteSumDiff(arr, arr2));
    }
}