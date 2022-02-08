#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=1001 lang=cpp
 *
 * [1001] 网格照明
 */

// @lc code=start
class Solution {
    struct pairHash {
       public:
        template <typename T, typename U>
        size_t operator()(const pair<T, U>& x) const {
            return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
        }
    };

   public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps,
                                 vector<vector<int>>& queries) {
        using Point = pair<int, int>;
        unordered_set<Point, pairHash> bulbs;
        // 行、列、左右截距
        unordered_map<int, int> row, col, left, right;
        for (const auto& lamp : lamps) {
            int x = lamp[0], y = lamp[1];
            if (!bulbs.count({x, y})) {
                bulbs.insert({x, y});
                row[x]++;
                col[y]++;
                left[x + y]++;
                right[x - y]++;
            }
        }

        // 开始查询
        vector<int> result = vector<int>(queries.size(), false);
        for (int i = 0; i < queries.size(); i++) {
            int x = queries[i][0], y = queries[i][1];
            // 检查查询点
            result[i] = row[x] || col[y] || left[x + y] || right[x - y];
            // 关闭查询点中心九宫格内的灯
            for (int i = max(x - 1, 0); i < min(x + 2, n); i++) {
                for (int j = max(y - 1, 0); j < min(y + 2, n); j++) {
                    if (bulbs.count({i, j})) {
                        bulbs.erase({i, j});
                        row[i]--, col[j]--, left[i + j]--, right[i - j]--;
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    json j;
    while (!in.eof()) {
        int n;
        in >> n;
        in >> j >> ws;
        vector<vector<int>> lamps = j.get<vector<vector<int>>>();
        in >> j >> ws;
        vector<vector<int>> queries = j.get<vector<vector<int>>>();

        print(Solution().gridIllumination(n, lamps, queries));
    }
}