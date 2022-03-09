#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=933 lang=cpp
 *
 * [933] 最近的请求次数
 */

// @lc code=start
class RecentCounter {
    queue<int> q;
    int range = 3000;
   public:
    RecentCounter() {}

    int ping(int t) {
        while(!q.empty()&&q.front()<t-range){
            q.pop();
        }
        q.push(t);
        return (int)q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto args = j.get<vector<vector<int>>>();
        auto r = RecentCounter();
        for (int i = 1; i < args.size(); i++) {
            print(r.ping(args[i][0]));
        }
    }
}