#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=436 lang=cpp
 *
 * [436] 寻找右区间
 */

// @lc code=start
class Solution {
   public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        unordered_map<int, int> indexOf;
        vector<int> allLefts = vector<int>(intervals.size());
        for (int i = 0; i < intervals.size(); i++) {
            int left      = intervals[i][0];
            indexOf[left] = i;
            allLefts[i]   = left;
        }
        sort(allLefts.begin(), allLefts.end());
        vector<int> result = vector<int>(intervals.size(), -1);
        for (int i = 0; i < result.size(); i++) {
            auto pos = lower_bound(allLefts.begin(), allLefts.end(), intervals[i][1]);
            if (pos != allLefts.end()){
                result[i]=indexOf[*pos];
            }
        }
        return result;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = getMatrix(str);
        print(Solution().findRightInterval(arr));
    }
}