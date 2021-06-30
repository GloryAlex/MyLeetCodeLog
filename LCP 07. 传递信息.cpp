#include "LeetCode.h"
using namespace std;

class Solution {
    vector<vector<int>> graph;
    vector<vector<int>> dp;
    int dfs(int remainSteps, int cur, int target) {
        if (dp[remainSteps][cur] != -1) return dp[remainSteps][cur];
        int total = 0;
        for (int i : graph[cur]) {
            total += dfs(remainSteps - 1, i, target);
        }
        return dp[remainSteps][cur] = total;
    }

   public:
    int numWays(int n, vector<vector<int>>& relations, int k) {
        dp = vector<vector<int>>(k + 1, vector<int>(n, -1));
        for (int i = 0; i < n; i++) dp[0][i] = 0;
        dp[0][n - 1] = 1;
        //建图
        graph = vector<vector<int>>(n);
        for (const auto& relation : relations) {
            graph[relation[0]].push_back(relation[1]);
        }
        // dfs搜索
        return dfs(k, 0, n - 1);
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        int n, k;
        string str;
        in >> n >> str >> k;
        auto matrix = getMatrix(str);
        print(Solution().numWays(n, matrix, k));
    }
}