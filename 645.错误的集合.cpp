#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=645 lang=cpp
 *
 * [645] 错误的集合
 */

// @lc code=start
class Solution {
   public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> arr(nums.size()+1);
        for(int i:nums)arr[i]++;
        vector<int> ret(2);
        for(int i=1;i<=nums.size();i++){
            if(arr[i]>1)ret[0]=i;
            if(arr[i]<1)ret[1]=i;
        }
        return ret;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = getArray(str);
        print(Solution().findErrorNums(arr))
    }
}