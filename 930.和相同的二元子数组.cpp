#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=930 lang=cpp
 *
 * [930] 和相同的二元子数组
 */

// @lc code=start
class Solution {
 public:
  int numSubarraysWithSum(vector<int>& nums, int goal) {
    unordered_map<int, int> preSum = unordered_map<int, int>();
    int total = 0, sum = 0;
    for (int i:nums) {
      preSum[sum]++;
      sum += i;
      if (preSum.count(sum - goal)) {
        total += preSum[sum - goal];
      }
    }
    return total;
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
    print(Solution().numSubarraysWithSum(arr, n));
  }
}