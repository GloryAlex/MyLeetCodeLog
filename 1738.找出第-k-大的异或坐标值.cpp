#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=1738 lang=cpp
 *
 * [1738] 找出第 K 大的异或坐标值
 */

// @lc code=start
class Solution {
   public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        auto xorMatrix = vector<vector<int>>(m + 1, vector<int>(n + 1));

        auto q = priority_queue<int, vector<int>, greater<int>>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                xorMatrix[i + 1][j + 1] = xorMatrix[i][j + 1] ^
                                          xorMatrix[i + 1][j] ^
                                          xorMatrix[i][j] ^ matrix[i][j];
                q.push(xorMatrix[i + 1][j + 1]);
                if (q.size() > k) q.pop();
            }
        }
        return q.top();
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        int k;
        in >> str >> k;
        auto matrix = getMatrix(str);
        cout << Solution().kthLargestValue(matrix, k) << endl;
    }
}