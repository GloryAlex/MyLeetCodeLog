#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=691 lang=cpp
 *
 * [691] 贴纸拼词
 */

// @lc code=start
class Solution {
   public:
    int minStickers(vector<string>& stickers, string target) {
        int m = target.size();
        auto dp = unordered_map<int, int>({{0, 0}});
        function<int(int)> dfs = [&](int mask) -> int {
            if (dp.count(mask)) return dp[mask];
            dp[mask] = m + 1;
            for (const auto& sticker : stickers) {
                int remain = mask;
                auto cnt = vector<int>(26, 0);
                for (char c : sticker) cnt[c - 'a']++;
                for (int i = 0; i < m; i++) {
                    if (((mask >> i) & 1) && cnt[target[i] - 'a'] > 0) {
                        cnt[target[i] - 'a']--;
                        remain ^= (1 << i);
                    }
                }

                if (remain < mask) {
                    dp[mask] = min(dp[mask], dfs(remain) + 1);
                }
            }
            return dp[mask];
        };
        int res = dfs((1 << m) - 1);
        return res > m ? -1 : res;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j, k;
        in >> j >> k >> ws;
        auto s = j.get<vector<string>>();
        auto t = k.get<string>();
        print(Solution().minStickers(s, t));
    }
}