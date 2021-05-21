#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=1035 lang=cpp
 *
 * [1035] 不相交的线
 */

// @lc code=start
class Solution {
   public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int length1 = nums1.size(), length2 = nums2.size();
        auto dp = vector<vector<int>>(length1 + 1, vector<int>(length2 + 1));
        for (int i = 0; i < length1; i++)
            for (int j = 0; j < length2; j++)
                dp[i + 1][j + 1] = nums1[i] == nums2[j]
                                       ? dp[i][j] + 1
                                       : max(dp[i][j + 1], dp[i + 1][j]);

        return dp[length1][length2];
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string s1, s2;
        in >> s1 >> s2;
        auto arr1 = getArray(s1);
        auto arr2 = getArray(s2);
        cout << Solution().maxUncrossedLines(arr1, arr2) << endl;
    }
}