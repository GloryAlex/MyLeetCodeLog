#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=611 lang=cpp
 *
 * [611] 有效三角形的个数
 */

// @lc code=start
class Solution {
   public:
    int triangleNumber(vector<int>& nums) {
        int total = 0;
        sort(nums.begin(), nums.end());
        for (auto i = nums.begin(), end = nums.end(); i < end; i++) {
            for (auto j = i + 1; j < end; j++) {
                int diff = *j - *i;
                int sum = *j + *i;
                auto l = upper_bound(j + 1, end, diff);
                auto r = lower_bound(j + 1, end, sum);
                total += max(0L, r - l);
            }
        }
        return total;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = getArray(str);
        print(Solution().triangleNumber(arr));
    }
}