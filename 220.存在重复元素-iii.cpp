#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long> tree;
        auto isValid = [&](long i){
            auto it = tree.lower_bound(i-t);

            if(it!=tree.end()&&*it<=i+t)return true;
            return false;
        };
        
        for(int i=0;i<nums.size();i++){
            if(i>k)tree.erase(tree.find(nums[i-k-1]));

            if(isValid(nums[i]))return true;
            else tree.insert(nums[i]);
        }
        return false;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        int k, t;
        json j;
        in >> j >> k >> t >> ws;
        auto arr = j.get<vector<int>>();
        print(Solution().containsNearbyAlmostDuplicate(arr, k, t));
    }
}