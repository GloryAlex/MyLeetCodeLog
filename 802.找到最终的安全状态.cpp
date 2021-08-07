#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=802 lang=cpp
 *
 * [802] 找到最终的安全状态
 */

// @lc code=start
class Solution {
    public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // 构造反图
        auto reverseGraph = vector<vector<int>>(graph.size());
        auto degree = vector<int>(graph.size());
        for (int i = 0; i < graph.size(); i++) {
            for (int next : graph[i]){
                reverseGraph[next].emplace_back(i);
                degree[i]++;
            }
        }
        // 拓扑排序
        vector<int> result;
        queue<int> q;
        for(int i=0;i<degree.size();i++)
            if(!degree[i])q.push(i);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            result.push_back(cur);
            for(int next:reverseGraph[cur]){
                if(!--degree[next])q.push(next);
            }
        }
        sort(result.begin(),result.end());
        return result;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = getMatrix(str);
        print(Solution().eventualSafeNodes(arr));
    }
}