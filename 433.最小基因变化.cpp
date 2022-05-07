#include "lib/leetcode.h"
using namespace std;

/*
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
 */

// @lc code=start
class Solution {
   public:
    int minMutation(string start, string end, vector<string>& bank) {
        const int INVALID_MUTATE = -1;
        auto validMove = [](const string& a, const string& b) {
            int cnt = 0;
            for (int i = 0; i < 8; i++) cnt += (a[i] != b[i]);
            return cnt == 1;
        };
        // 添加初始
        auto startPos = -1, endPos = -1;
        for (int i = 0; i < bank.size(); i++) {
            if (bank[i] == start)
                startPos = i;
            else if (bank[i] == end)
                endPos = i;
        }
        if (startPos == -1) {
            startPos = bank.size();
            bank.emplace_back(start);
        }
        if (endPos == -1) return INVALID_MUTATE;
        // 构建图
        vector<vector<int>> grids(bank.size());
        for (int i = 0; i < bank.size(); i++) {
            for (int j = i + 1; j < bank.size(); j++) {
                if (validMove(bank[i], bank[j])) {
                    grids[i].push_back(j);
                    grids[j].push_back(i);
                }
            }
        }
        // bfs
        auto hasVisit = vector<int>(bank.size(), false);
        auto q = queue<int>({startPos});
        for (int steps = 0; !q.empty(); steps++) {
            int size = q.size();
            while (size--) {
                auto cur = q.front();
                q.pop();
                if (cur == endPos) return steps;
                hasVisit[cur] = true;
                for (int next : grids[cur]) {
                    if (hasVisit[next] == false) q.push(next);
                }
            }
        }
        return INVALID_MUTATE;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string m, n;
        string str;
        in >> m >> n >> str >> ws;
        m = m.substr(1, m.size() - 2);
        n = n.substr(1, n.size() - 2);
        auto arr = getStringArray(str);
        print(Solution().minMutation(m, n, arr));
    }
}