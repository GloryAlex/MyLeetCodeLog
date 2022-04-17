#include "lib/leetcode.h"
using namespace std;

class Solution {
    pair<int, int> getTwoAndFive(long long n) {
        auto res = pair<int, int>();
        auto b = n;
        while (b % 2 == 0) {
            res.first++;
            b /= 2;
        }
        while (n % 5 == 0) {
            res.second++;
            n /= 5;
        }
        return res;
    }
    pair<int, int> add(pair<int, int> a, pair<int, int> b) {
        return {a.first + b.first, a.second + b.second};
    }
    pair<int, int> minus(pair<int, int> a, pair<int, int> b) {
        return {a.first - b.first, a.second - b.second};
    }
    int numOfTen(pair<int, int> a, pair<int, int> b) {
        auto c = add(a, b);
        return min(c.first, c.second);
    }

   public:
    int maxTrailingZeros(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        // 计算二维前缀和
        auto rowPreSum =
            vector<vector<pair<int, int>>>(m, vector<pair<int, int>>(n));
        auto colPreSum = rowPreSum;

        for (int i = 0; i < m; i++) {
            rowPreSum[i][0] = getTwoAndFive(grid[i][0]);
            for (int j = 1; j < n; j++) {
                rowPreSum[i][j] =
                    add(rowPreSum[i][j - 1], getTwoAndFive(grid[i][j]));
            }
        }

        for (int j = 0; j < n; j++) {
            colPreSum[0][j] = getTwoAndFive(grid[0][j]);
            for (int i = 1; i < m; i++) {
                colPreSum[i][j] =
                    add(colPreSum[i - 1][j], getTwoAndFive(grid[i][j]));
            }
        }
        // 计算每格子的最值
        int maxRes = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                auto left = j == 0 ? pair<int, int>{0, 0} : rowPreSum[i][j - 1];
                auto right = minus(rowPreSum[i][n - 1], rowPreSum[i][j]);
                auto up = colPreSum[i][j];
                auto down = minus(
                    colPreSum[m - 1][j],
                    (i == 0 ? pair<int, int>{0, 0} : colPreSum[i - 1][j]));

                int curSum =
                    max(max(numOfTen(left, up), numOfTen(left, down)),
                        max(numOfTen(right, up), numOfTen(right, down)));
                maxRes = max(maxRes, curSum);
                cout<<endl;
            }
        }
        return maxRes;
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto grid = j.get<vector<vector<int>>>();
        print(Solution().maxTrailingZeros(grid));
    }
}