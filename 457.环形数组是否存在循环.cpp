#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=457 lang=cpp
 *
 * [457] 环形数组是否存在循环
 */

// @lc code=start
class Solution {
    // 用于在循环数组中计算
    int nextPos(int pos, int step, int length) {
        return ((pos + step) % length + length) % length;
    }
    // 通过拓扑排序来确定图中是否有环
    // 图中每个元素要么有一个相连的结点
    // 要么没有结点（用 -1 表示）
    bool existRing(vector<int> graph) {
        vector<int> degree = vector<int>(graph.size(), 0);
        queue<int> q = queue<int>();
        // 构造入度
        for (int destPoint : graph)
            if (destPoint >= 0) degree[destPoint]++;
        // 将入度为 0 的结点加入队列
        for (int i = 0; i < degree.size(); i++)
            if (!degree[i]) q.push(i);
        // 拓扑排序
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (graph[cur] >= 0 && !--degree[graph[cur]]) q.push(graph[cur]);
        }
        // 如果还有入度不为 0 的结点，则说明存在环
        return any_of(degree.begin(), degree.end(), [](int a) -> bool { return a; });
    }
    // 构造用于拓扑排序的特定的图
    // 只有当结点指向的方向满足特定条件时才会将这条边加入图
    // 此外，自环不纳入考虑
    vector<int> buildGraphIf(function<bool(int)> isOK, vector<int>& nums) {
        vector<int> graph = vector<int>(nums.size(), -1);
        for (int i = 0; i < graph.size(); i++) {
            if (isOK(nums[i])) {
                int next = nextPos(i, nums[i], nums.size());
                if (next != i) graph[i] = next;
            }
        }
        return graph;
    }

   public:
    bool circularArrayLoop(vector<int>& nums) {
        return existRing(move(buildGraphIf([](int a) { return a > 0; }, nums))) || // 正向图没有环
               existRing(move(buildGraphIf([](int a) { return a < 0; }, nums))); // 逆向图也没有环
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = getArray(str);
        print(Solution().circularArrayLoop(arr));
    }
}