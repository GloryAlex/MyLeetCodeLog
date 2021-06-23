#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=1658 lang=cpp
 *
 * [1658] 将 x 减到 0 的最小操作数
 */

// @lc code=start
class Solution {
 public:
  int minOperations(vector<int>& nums, int x) {
    //求出数组总和
    int sum = accumulate(nums.begin(), nums.end(), 0);
    //判断特殊情况
    if (sum < x) return -1;
    else if (sum == x) return nums.size();
    //求出和为sum-x的最长连续子序列
    //双指针求解
    int maxLength = -1, target = sum - x, curSum = 0;
    for (int i = 0, j = 0; i < nums.size(); i++) {
      //移动右指针
      while (j < nums.size() && curSum < target) {
        curSum += nums[j];
        j++;
      }
      if (curSum == target) maxLength = max(j - i, maxLength);
      //移动左指针
      curSum -= nums[i];
    }
    //此时减去该序列的长度即为最短操作数
    return maxLength == -1 ? -1 : (int)nums.size() - maxLength;
  }
};
// @lc code=end
int main() {
  ifstream in("input");
  while (!in.eof()) {
    string str;
    int n;
    in >> str >> n;
    auto arr = getArray(str);
    print(Solution().minOperations(arr, n));
  }
}
