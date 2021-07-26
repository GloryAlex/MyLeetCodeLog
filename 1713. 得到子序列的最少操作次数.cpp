#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=1713 lang=cpp
 *
 * [1713] 得到子序列的最少操作次数
 */

// @lc code=start
class Solution {
   public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        // 坐标变换
        unordered_map<int, int> pos;
        for (int i = 0; i < target.size(); i++) pos[target[i]] = i;
        // 求 arr 的最长递增子序列
        vector<int> lic = vector<int>();
        for (int i : arr) {
            if (pos.count(i)) {
                auto idx = pos[i];
                auto it  = lower_bound(lic.begin(), lic.end(), idx);
                if (it != lic.end())
                    *it = idx;
                else
                    lic.push_back(idx);
            }
        }
        return target.size() - lic.size();
    }
};
// @lc code=end
int main() {
    ifstream in("input");
    while (!in.eof()) {
        string targetStr, arrStr;
        in >> targetStr >> arrStr;
        auto target = getArray(targetStr), arr = getArray(arrStr);
        print(Solution().minOperations(target, arr));
    }
}
