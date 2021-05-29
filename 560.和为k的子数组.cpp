#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */

// @lc code=start
class Solution {
   public:
    int subarraySum(vector<int>& nums, int target) {
        auto preSums = unordered_map<int,int>({{0,1}});
        int total = 0,count=0;
        for(int i:nums){
            total+=i;
            count+=preSums[total-target];
            preSums[total]++;
        }
        return count;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        int k;
        in >> str >> k;
        auto arr = getArray(str);
        cout << Solution().subarraySum(arr, k);
    }
}