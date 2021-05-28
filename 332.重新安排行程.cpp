#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
class Solution {
   private:
    typedef priority_queue<string, vector<string>,
                           function<bool(const string&, const string&)>>
        priorityQueue;
    typedef unordered_map<string, priorityQueue> graphType;

    void dfs(string cur, vector<string>& path, graphType& graph) {
        while (!graph[cur].empty()) {
            string city = graph[cur].top();
            graph[cur].pop();
            dfs(city, path, graph);
        }
        path.push_back(cur);
    }

   public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //建图
        auto comperator = [=](const string&a,const string& b){return a>b;};
        auto graph = graphType();
        for (const auto& ticket : tickets) {
            if(!graph.count(ticket[0]))graph[ticket[0]]=priorityQueue(comperator);
            graph[ticket[0]].push(ticket[1]);
        }
        vector<string> result;
        dfs("JFK", result, graph);
        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = getStringMatrix(str);
        print(Solution().findItinerary(arr));
    }
}