#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=789 lang=cpp
 *
 * [789] 逃脱阻碍者
 */

 // @lc code=start
class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        auto distanceOf = [](const vector<int>& a, const vector<int>& b) {
            return abs(a[0] - b[0]) + abs(a[1] - b[1]);
        };
        auto start = vector<int>{ 0,0 };
        int leastSteps = distanceOf(start, target);
        for (const auto& ghost : ghosts)
            if (distanceOf(ghost, target) <= leastSteps)return false;

        return true;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = getMatrix(str);
        in >> str;
        auto target = getArray(str);
        print(Solution().escapeGhosts(arr, target));
    }
}