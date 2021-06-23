#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H 指数 II
 */

// @lc code=start
class Solution {
 public:
  int hIndex(vector<int>& citations) {
    int length = citations.size(), left = 0, right = length - 1;
    while (left < right) {
      int mid = (right - left) / 2 + left;
      if (citations[mid] < length - mid)
        left = mid + 1;
      else
        right = mid;
    }
    return min(length - left, citations[left]);
  }
};
// @lc code=end
int main() {
  ifstream in("input");
  while (!in.eof()) {
    string str;
    in >> str;
    auto arr = getArray(str);
    print(Solution().hIndex(arr));
  }
}
