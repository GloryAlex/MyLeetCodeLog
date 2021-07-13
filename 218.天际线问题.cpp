#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=218 lang=cpp
 *
 * [218] 天际线问题
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        using point     = pair<int, int>;
        auto cmp        = [](const point& a, const point& b) { return a.second < b.second; };
        auto q          = priority_queue<point, vector<point>, decltype(cmp)>(cmp);
        auto boundaries = vector<int>();
        auto result     = vector<vector<int>>();
        for (auto& building : buildings) {
            boundaries.emplace_back(building[0]);
            boundaries.emplace_back(building[1]);
        }
        sort(boundaries.begin(), boundaries.end());
        int length = buildings.size(), index = 0;
        for (auto& boundary : boundaries) {
            while (index < length && buildings[index][0] <= boundary) {
                q.emplace(buildings[index][1], buildings[index][2]);
                index++;
            }
            while (!q.empty() && q.top().first <= boundary) {
                q.pop();
            }
            int maxn = q.empty() ? 0 : q.top().second;
            if (result.empty() || result.back().at(1) != maxn) {
                result.push_back(vector<int>{boundary, maxn});
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
        auto buildings = getMatrix(str);
        print(Solution().getSkyline(buildings));
    }
}