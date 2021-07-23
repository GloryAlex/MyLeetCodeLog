#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=1893 lang=cpp
 *
 * [1893] 检查是否区域内所有整数都被覆盖
 */

// @lc code=start
class Solution {
   public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> diff = vector<int>(52);
        for (auto& range : ranges) {
            diff[range[0]]++;
            diff[range[1] + 1]--;
        }
        int cur = 0;
        for (int i = 0; i <= 50; i++) {
            cur += diff[i];
            if (i >= left && i <= right && cur <= 0) return false;
        }
        return true;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        int left, right;
        in >> str >> left >> right;
        auto arr = getMatrix(str);
        print(Solution().isCovered(arr, left, right));
    }
}