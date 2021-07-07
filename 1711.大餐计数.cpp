#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=1711 lang=cpp
 *
 * [1711] 大餐计数
 */

// @lc code=start
class Solution {
 public:
  int countPairs(vector<int>& deliciousness) {
    const int MOD = 1e9 + 7;
    int maxSum = 2 * *max_element(deliciousness.begin(), deliciousness.end());
    int total = 0;
    unordered_map<int, int> allDili;
    for (int delicious : deliciousness) {
      for (int i = 1; i <= maxSum; i <<= 1) {
        if (allDili.count(i-delicious)){
          total = (total+allDili[i-delicious])%MOD;
        } 
      }
      allDili[delicious]++;
    }
    return total;
  }
};
// @lc code=end

int main() {
  ifstream in("input");
  while (!in.eof()) {
    string str;
    in >> str;
    auto arr = getArray(str);
    print(Solution().countPairs(arr));
  }
}