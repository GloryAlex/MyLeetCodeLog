#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=815 lang=cpp
 *
 * [815] 公交路线
 */

// @lc code=start
class Solution {
 public:
  int numBusesToDestination(vector<vector<int>>& routes, int source,
                            int target) {
    if (source == target) return 0;
    // 记录每个站所属的公交线路
    unordered_map<int, vector<int>> allStops;
    for (int i = 0; i < routes.size(); i++) {
      for (int stop : routes[i]) {
        allStops[stop].push_back(i);
      }
    }
    // 连接每个站所属的所有公交线路
    vector<unordered_set<int>> routeMap(routes.size());
    for (const auto& [stop, crossRoutes] : allStops) {
      for (int route : crossRoutes) {
        routeMap[route].insert(crossRoutes.begin(), crossRoutes.end());
      }
    }
    for (int i = 0; i < routeMap.size(); i++) {
      routeMap[i].erase(i);
    }
    // BFS
    unordered_set<int> targetRoutes(allStops[target].begin(),
                                    allStops[target].end());
    vector<int> hasVisit(routes.size());
    queue<int> q;
    for (int beginRoute : allStops[source]) {
      q.push(beginRoute);
      hasVisit[beginRoute] = true;
    }
    for (int step = 1; !q.empty(); step++) {
      int size = q.size();
      while (size--) {
        int curRoute = q.front();
        q.pop();
        if (targetRoutes.count(curRoute)) return step;
        for (int nextRoute : routeMap[curRoute]) {
          if (!hasVisit[nextRoute]) {
            hasVisit[nextRoute] = true;
            q.push(nextRoute);
          }
        }
      }
    }
    return -1;
  }
};
// @lc code=end

int main() {
  ifstream in("input");
  while (!in.eof()) {
    string str;
    int a, b;
    in >> str >> a >> b;
    auto arr = getMatrix(str);
    cout << Solution().numBusesToDestination(arr, a, b) << endl;
  }
}