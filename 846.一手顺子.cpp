#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=846 lang=cpp
 *
 * [846] 一手顺子
 */

// @lc code=start
class Solution {
 public:
  bool isNStraightHand(vector<int>& hand, int groupSize) {
    if(hand.size()%groupSize)return false;
    map<int,int> dict;
    for(int i:hand)dict[i]++;
    while(!dict.empty()){
        int val = dict.begin()->first;
        int size=dict.begin()->second;
        for(int i=0;i<groupSize;i++){
            auto it = dict.find(val+i);
            if(it==dict.end()||it->second<size)return false;
            it->second-=size;
            if(!it->second)dict.erase(it);
        }
    }
    return true;
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
    print(Solution().isNStraightHand(arr, n));
  }
}