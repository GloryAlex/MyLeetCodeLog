#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start
class Solution {
   public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        auto dp = vector<vector<int>>(len1 + 1, vector<int>(len2 + 1));

        int ret = 0;
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                if (nums1[i] == nums2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                    ret = max(ret, dp[i + 1][j + 1]);
                }
            }
        }
        return ret;
    }
};
// @lc code=end
int main() {
    ifstream in("input");
    while (!in.eof()) {
        string s1, s2;
        in >> s1 >> s2;
        auto a = getArray(s1);
        auto b = getArray(s2);
        cout << Solution().findLength(a, b) << endl;
    }
}
