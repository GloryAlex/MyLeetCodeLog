#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=1074 lang=cpp
 *
 * [1074] 元素和为目标值的子矩阵数量
 */

// @lc code=start
class Solution {
   private:
    int getSubArrayTarget(vector<int>& nums, int target) {
        auto preSum = unordered_map<int, int>({{0, 1}});
        int total = 0, count = 0;
        for (int i : nums) {
            total += i;
            if (preSum.count(total - target)) count += preSum[total - target];
            preSum[total]++;
        }
        return count;
    }
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        auto result = vector<vector<int>>(n, vector<int>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[j][i] = matrix[i][j];
            }
        }
        return result;
    }

   public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        if(m>n){
            matrix=transpose(matrix);
            swap(m,n);
        }
        int count = 0;
        for (int i = 0; i < m; i++) {
            //枚举上边界
            auto cur = vector<int>(n);
            for (int j = i; j < m; j++) {
                //枚举下边界
                for (int k = 0; k < n; k++) cur[k] += matrix[j][k];
                count += getSubArrayTarget(cur, target);
            }
        }
        return count;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        int k;
        in >> str >> k;
        auto arr = getMatrix(str);
        cout << Solution().numSubmatrixSumTarget(arr, k) << endl;
    }
}