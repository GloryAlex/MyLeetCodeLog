#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0,result=0;
        unordered_map<int,int> preSums;
        preSums.insert({0,1});
        for(int i:nums){
            sum+=i;
            if(preSums.count(sum-k))result+=preSums[sum-k];
            preSums[sum]++;
        }
        return result;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        int k;
        in >> k >> ws;
        auto nums = j.get<vector<int>>();
        print(Solution().subarraySum(nums, k));
    }
}