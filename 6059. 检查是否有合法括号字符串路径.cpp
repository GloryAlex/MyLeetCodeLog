#include "lib/leetcode.h"
using namespace std;

class Solution {
   public:
    bool hasValidPath(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0][0] == ')' || grid.back().back() == '(')
            return false;
        int m = grid.size(), n = grid[0].size();
        auto isValid = [&](int x, int y) {
            return x >= 0 && y >= 0 && x < m && y < n;
        };
        auto hasVisit = vector<vector<vector<int>>>(
            m, vector<vector<int>>(n, vector<int>(m + n, false)));

        function<bool(int, int, int)> dfs;
        dfs = [&](int x, int y, int cnt) {
            cnt += (grid[x][y] == '(' ? 1 : -1);
            if (x == m - 1 && y == n - 1) return !cnt;
            if (cnt < 0 || hasVisit[x][y][cnt]) return false;
            hasVisit[x][y][cnt] = true;
            // 向下
            if (isValid(x + 1, y) && dfs(x + 1, y, cnt)) return true;
            // 向右
            if (isValid(x, y + 1) && dfs(x, y + 1, cnt)) return true;
            return false;
        };
        return dfs(0, 0, 0);
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto k = j.get<vector<vector<string>>>();
        auto grid = vector<vector<char>>();
        for (int i = 0; i < k.size(); i++) {
            grid.push_back(vector<char>());
            for (int j = 0; j < k[i].size(); j++) {
                grid[i].push_back(k[i][j][0]);
            }
        }
        print(Solution().hasValidPath(grid));
    }
}