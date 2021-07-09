#include "LeetCode.h"
using namespace std;

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    if (nums.empty()) return -1;
    pair<int, int> major = {nums[0], 0};
    for (int i : nums) {
      if (major.first == i)
        major.second++;
      else {
        major.second--;
        if (major.second <= 0) major = {i, 1};
      }
    }
    major.second = 0;
    for (int i : nums)
      if (i == major.first) major.second++;
    return (major.second > nums.size() / 2)?major.first:-1;
  }
};

int main() {
  ifstream in("input");
  while (!in.eof()) {
    string str;
    in >> str;
    auto arr = getArray(str);
    print(Solution().majorityElement(arr));
  }
}