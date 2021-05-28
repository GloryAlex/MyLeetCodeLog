#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=477 lang=cpp
 *
 * [477] 汉明距离总和
 */

// @lc code=start
class Solution {
   public:
    int totalHammingDistance(vector<int>& nums) {
        int result = 0;
        int n=nums.size();
        for(int i=31;i>=0;i--){
            int c = 0;
            for(int num:nums){
                c+=(num>>i)&1;
            }
            result+=c*(n-c);
        }
        return result;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = getArray(str);
        cout << Solution().totalHammingDistance(arr) << endl;
    }
}