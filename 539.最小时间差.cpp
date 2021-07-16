#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=539 lang=cpp
 *
 * [539] 最小时间差
 */

// @lc code=start
class Solution {
    static int valueOf(const string& str) {
        auto pos = str.begin();
        while (*pos != ':') pos++;
        return stoi(string(str.begin(), pos)) * 60 +
               stoi(string(pos + 1, str.end()));
    }

   public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> times = vector<int>(timePoints.size());
        for (int i = 0; i < timePoints.size(); i++)
            times[i] = Solution::valueOf(timePoints[i]);
        sort(times.begin(), times.end());

        int minDiff = 24 * 60 - times.back() + times.at(0);
        for (int i = 1; i < times.size(); i++) {
            minDiff = min(minDiff, times[i] - times[i - 1]);
        }
        return minDiff;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = getStringArray(str);
        print(Solution().findMinDifference(arr));
    }
}