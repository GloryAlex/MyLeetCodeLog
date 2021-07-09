#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=492 lang=cpp
 *
 * [492] 构造矩形
 */

// @lc code=start
class Solution {
 public:
  vector<int> constructRectangle(int area) {
    int width = sqrt(area);
    while (area % width) width--;
    return {area/width, width};
  }
};
// @lc code=end

int main() {
  ifstream in("input");
  while (!in.eof()) {
    int n;
    in >> n;
    print(Solution().constructRectangle(n));
  }
}