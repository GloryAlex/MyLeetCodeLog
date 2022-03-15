#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=2044 lang=cpp
 *
 * [2044] 统计按位或能得到最大值的子集数目
 */

// @lc code=start
class Solution {
   public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOrValue = 0;
        for (int i : nums) maxOrValue |= i;

        int total = 0;
        
        function<void(int, int)> dfs;
        dfs = [&](int orValue, int index) {
            if (index >= nums.size()) {
                total += orValue == maxOrValue;
            } else {
                dfs(orValue, index + 1);
                dfs(orValue | nums[index], index + 1);
            }
        };

        dfs(0, 0);
        return total;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto arr = j.get<vector<int>>();
        print(Solution().countMaxOrSubsets(arr));
    }
}