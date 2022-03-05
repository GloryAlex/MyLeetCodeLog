#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=539 lang=cpp
 *
 * [539] 最小时间差
 */

// @lc code=start
class Solution {
   public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes = vector<int>(timePoints.size());
        transform(timePoints.begin(), timePoints.end(), minutes.begin(),
                  [](string timePoint) {
                      auto i = timePoint.begin();
                      while (i != timePoint.end() && *i != ':') i++;
                      if (i == timePoint.end()) throw "Cannot transfer to int";
                      return stoi(string(timePoint.begin(), i)) * 60 +
                             stoi(string(i + 1, timePoint.end()));
                  });
        sort(minutes.begin(), minutes.end());

        minutes.push_back(1440 + minutes[0]);
        int minDiff = 1440;
        for (int i = 1; i < minutes.size(); i++) {
            minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
        }

        return minDiff;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto arr = j.get<vector<string>>();
        print(Solution().findMinDifference(arr));
    }
}