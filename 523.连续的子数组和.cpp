#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=523 lang=cpp
 *
 * [523] 连续的子数组和
 */

// @lc code=start
class Solution {
   public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        auto dict = unordered_map<int,int>({{0,-1}});
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            sum%=k;
            if(dict.count(sum)){
                if(i-dict[sum]>=2)return true;
            }else{
                dict[sum]=i;
            }
        }
        return false;
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
        print(Solution().checkSubarraySum(arr, n));
    }
}