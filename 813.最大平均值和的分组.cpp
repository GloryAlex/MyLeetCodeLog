#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=813 lang=cpp
 *
 * [813] 最大平均值和的分组
 */

// @lc code=start
class Solution {
    vector<vector<double>> dp;

   private:
    double getMaxSumOfAverage(vector<int>& preSum, int remain, int index) {
        if(dp[remain][index]!=-1)return dp[remain][index];
        double ret = 0.0;
        for (int i = index + 1; i < (int)preSum.size() - remain; i++) {
            double cur =
                (double)(preSum[i] - preSum[index]) / (double)(i - index);
            double next = getMaxSumOfAverage(preSum, remain - 1, i);
            ret = max(ret, cur + next);
        }
        return dp[remain][index] = ret;
    }

   public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        auto preSum = vector<int>(nums.size() + 1);
        preSum.resize(1);
        for (int i : nums) {
            preSum.push_back(preSum.back() + i);
        }
        dp = vector<vector<double>>(k, vector<double>(nums.size() + 1, -1.0));
        for (int i = 0; i < nums.size(); i++)
            dp[0][i] =
                (double)(preSum.back() - preSum[i]) / (double)(nums.size() - i);
        return getMaxSumOfAverage(preSum, k - 1, 0);
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
        cout << Solution().largestSumOfAverages(arr, k) << endl;
    }
}