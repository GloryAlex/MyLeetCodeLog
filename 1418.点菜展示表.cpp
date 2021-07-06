#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=1418 lang=cpp
 *
 * [1418] 点菜展示表
 */

// @lc code=start
class Solution {
 public:
  vector<vector<string>> displayTable(vector<vector<string>>& orders) {
    map<int, unordered_map<string, int>> restaurant;
    set<string> allDishes;
    for (const auto& order : orders) {
      int number = stoi(order[1]);
      string dish = order[2];
      restaurant[number][dish]++;
      allDishes.insert(dish);
    }
    vector<vector<string>> result;
    //统计菜肴
    result.push_back({"Table"});
    result.back().insert(result.back().end(),allDishes.begin(),allDishes.end());
    //统计餐桌
    for(auto&[index,table]:restaurant){
        result.push_back({to_string(index)});
        for(int i=1;i<result[0].size();i++){
            const string& dish = result[0][i];
            result.back().push_back(table.count(dish)?to_string(table[dish]):"0");
        }
    }
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
    print(Solution().displayTable(arr));
  }
}