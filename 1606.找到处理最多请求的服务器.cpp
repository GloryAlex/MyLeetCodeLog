#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=1606 lang=cpp
 *
 * [1606] 找到处理最多请求的服务器
 */

// @lc code=start
class Solution {
   public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>
            worker;
        vector<int> frequenceOf = vector<int>(k);
        for (int i = 0; i < k; i++) available.insert(i);

        int maxLoad = 0;
        for (int i = 0; i < arrival.size(); i++) {
            int curTime = arrival[i];
            while (!worker.empty() && worker.top().first <= curTime) {
                available.insert(worker.top().second);
                worker.pop();
            }
            // 如果没有可用的服务器则舍弃任务
            if (available.empty()) continue;
            // 否则寻找第 i%k 个服务器（或其下一个服务器）
            int serverId;
            auto it = available.lower_bound(i % k);
            serverId = it == available.end() ? *available.begin() : *it;
            // 计数
            worker.push({curTime + load[i], serverId});
            available.erase(serverId);
            maxLoad = max(++frequenceOf[serverId], maxLoad);
        }

        vector<int> res;
        for (int i = 0; i < k; i++) {
            if (frequenceOf[i] == maxLoad) res.push_back(i);
        }
        return res;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j, l;
        int k;
        in >> k >> j >> l >> ws;
        auto a = j.get<vector<int>>();
        auto lo = l.get<vector<int>>();
        print(Solution().busiestServers(k, a, lo));
    }
}