#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=1583 lang=cpp
 *
 * [1583] 统计不开心的朋友
 */

 // @lc code=start
class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<vector<int>> prefs = vector<vector<int>>(n,vector<int>(n));
        vector<int> matches = vector<int>(n);
        // 预处理
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n - 1;j++) {
                prefs[i][preferences[i][j]] = j;
            }
        }
        for (const auto& pair : pairs) {
            matches[pair[0]] = pair[1];
            matches[pair[1]] = pair[0];
        }
        // 遍历查找
        int unhappyCount = 0;
        for (int x = 0;x < n;x++) {
            int y = matches[x];
            int orderIndex = prefs[x][y];
            for (int i = 0;i < orderIndex;i++) {
                int u = preferences[x][i];
                int v = matches[u];
                if (prefs[u][x] < prefs[u][v]) {
                    unhappyCount++;
                    break;
                }
            }
        }
        return unhappyCount;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str, s2;
        int n;
        in >> n >> str >> s2;
        auto arr = getMatrix(str);
        auto arr2 = getMatrix(s2);
        print(Solution().unhappyFriends(n, arr, arr2));
    }
}