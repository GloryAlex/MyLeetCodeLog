#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=352 lang=cpp
 *
 * [352] 将数据流变为多个不相交区间
 */

// @lc code=start
class SummaryRanges {
  map<int, int> leftAndRight;   //边界[左, 右]
  map<int, int> rightAndLeft;  //边界[右, 左]
 public:
  /** Initialize your data structure here. */
  SummaryRanges() {}

  void addNum(int val) {
    auto rightEdge = rightAndLeft.lower_bound(val);
    //无须合并区间
    if (rightEdge != rightAndLeft.end() && rightEdge->second /*左边界*/ <= val) return;
    //合并区间
    auto prev = rightAndLeft.find(val - 1);
    auto next = leftAndRight.find(val + 1);
    int l = (prev == rightAndLeft.end() ? val : prev->second);
    int r = (next == leftAndRight.end() ? val : next->second);
    if (prev != rightAndLeft.end() && next != leftAndRight.end()) {
      //[l,val-1],val和[val+1,r] -> [l,r]
      //删除原有区间
      leftAndRight
.erase(l);
      leftAndRight
.erase(val + 1);
      rightAndLeft.erase(r);
      rightAndLeft.erase(val - 1);
    } else if (prev != rightAndLeft.end()) {
      //[l,val-1]和val -> [l,val]
      rightAndLeft.erase(val - 1);
    } else if (next != leftAndRight.end()) {
      // val和[val+1,r] -> [val,r]
      leftAndRight
.erase(val + 1);
    }
    //合并区间
    leftAndRight[l] = r;
    rightAndLeft[r] = l;
  }

  vector<vector<int>> getIntervals() {
    vector<vector<int>> result;
    for (const auto& edge:leftAndRight){
        result.push_back({edge.first,edge.second});
    }
    return result;
  }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
// @lc code=end

int main() {
  ifstream in("input");
  while (!in.eof()) {
    string str;
    in >> str;
    auto arr = getArray(str);
    SummaryRanges range;
    for (int i : arr) range.addNum(i);
    print(range.getIntervals());
  }
}