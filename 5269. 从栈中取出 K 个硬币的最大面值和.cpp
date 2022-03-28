#include "lib/leetcode.h"
using namespace std;

class Solution {
    using Pile = vector<vector<int>>::iterator;
    Pile end;
    Pile begin;
    vector<vector<int>> dp;
    int dfs(Pile cur, int k, int remain) {
        if (dp[cur - begin][k] != -1) return dp[cur - begin][k];

        if (k == 0) {
            return dp[cur - begin][k] = 0;
        }
        if (cur == (end - 1)) {
            return dp[cur - begin][k] = cur->at(k - 1);
        }

        remain -= cur->size();

        int maxSum = 0;
        for (int i = max(k - remain - 1, -1), edge = min(k, (int)cur->size());
             i < edge; i++) {
            int curSum = (i == -1 ? 0 : cur->at(i));
            maxSum = max(maxSum, curSum + dfs(cur + 1, k - i - 1, remain));
        }
        return dp[cur - begin][k] = maxSum;
    }

   public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        dp = vector<vector<int>>(piles.size() + 1, vector<int>(k + 1, -1));

        int countCoins = 0;
        for (auto& pile : piles) {
            for (int i = 1; i < pile.size(); i++) {
                pile[i] += pile[i - 1];
            }
            countCoins += pile.size();
        }
        end = piles.end();
        begin = piles.begin();
        return dfs(piles.begin(), k, countCoins);
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto piles = j.get<vector<vector<int>>>();
        int k;
        in >> k >> ws;
        cout << Solution().maxValueOfCoins(piles, k) << endl;
    }
}