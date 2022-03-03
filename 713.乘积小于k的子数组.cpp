#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于K的子数组
 */

// @lc code=start
class Solution {
   public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int result = 0;
        int head=0,tail=0;
        long long product=1LL;
        while(tail<nums.size()){
            product *= nums[tail++];
            while(head<tail && product>=k){
                product /= nums[head++];
            }
            
            result += tail-head;
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
        auto nums = j.get<vector<int>>();
        int k;
        in >> k >> ws;
        print(Solution().numSubarrayProductLessThanK(nums, k));
    }
}