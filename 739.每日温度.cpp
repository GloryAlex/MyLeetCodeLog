#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> ordinal;
        auto res = vector<int>();
        for(auto i=(int)temperatures.size()-1;i>=0;i--){
            while(!ordinal.empty()&&ordinal.top().second<=temperatures[i]){
                ordinal.pop();
            }
            res.push_back(ordinal.empty()?0:ordinal.top().first-i);
            ordinal.push({i,temperatures[i]});
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto arr = j.get<vector<int>>();
        print(Solution().dailyTemperatures(arr));
    }
}