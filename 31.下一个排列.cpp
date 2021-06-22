#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
 public:
  template <typename T>
  void nextPermutation(vector<T>& nums) {
    int i = nums.size() - 2;
    for (; i >= 0; i--) {
      if (nums[i] < nums[i + 1]) break;
    }
    if (i >= 0) {
      int j = nums.size() - 1;
      for (; j >= 0; j--) {
        if (nums[i] < nums[j]) break;
      }
      swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
  }
};
// @lc code=end
int main() {
  ifstream in("input");
  while (!in.eof()) {
    string str;
    in >> str;
    auto arr = getArray(str);
    Solution().nextPermutation(arr);
    print(arr);
  }
}
