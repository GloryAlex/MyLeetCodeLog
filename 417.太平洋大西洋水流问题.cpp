#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        using point = pair<int, int>;
        if (heights.empty()) return {};
        int m = heights.size(), n = heights[0].size();
        const int PACIFIC = 0b01, ATLANTIC = 0b10;
        auto finalTargets = vector<vector<int>>(m, vector<int>(n, 0));
        auto pacificQueue = queue<point>();
        auto atlanticQueue = queue<point>();
        // 边界
        for (int i = 0; i < m; i++) {
            finalTargets[i][0] |= PACIFIC;
            finalTargets[i][n - 1] |= ATLANTIC;

            pacificQueue.push({i, 0});
            atlanticQueue.push({i, n - 1});
        }
        for (int j = 0; j < n; j++) {
            finalTargets[0][j] |= PACIFIC;
            finalTargets[m - 1][j] |= ATLANTIC;

            pacificQueue.push({0, j});
            atlanticQueue.push({m - 1, j});
        }

        auto validFlowFrom = [&](point& cur, point& prev) {
            return heights[cur.first][cur.second] <=
                   heights[prev.first][prev.second];
        };
        auto directions =
            vector<pair<int, int>>{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        auto isValid = [&](point& p) {
            return p.first >= 0 && p.first < m && p.second >= 0 && p.second < n;
        };
        auto bfs = [&](queue<point>& q, const int& mask) {
            while (!q.empty()) {
                auto cur = q.front();
                q.pop();

                finalTargets[cur.first][cur.second] |= mask;
                for (auto [dx, dy] : directions) {
                    auto prev = pair<int, int>{cur.first + dx, cur.second + dy};
                    if (isValid(prev) &&
                        !(finalTargets[prev.first][prev.second] & mask) &&
                        validFlowFrom(cur, prev)) {
                        q.push(prev);
                    }
                }
            }
        };

        bfs(pacificQueue, PACIFIC);
        bfs(atlanticQueue, ATLANTIC);

        auto res = vector<vector<int>>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (finalTargets[i][j] == (ATLANTIC | PACIFIC))
                    res.push_back({i, j});
            }
        }

        return res;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto grid = j.get<vector<vector<int>>>();
        print(Solution().pacificAtlantic(grid));
    }
}