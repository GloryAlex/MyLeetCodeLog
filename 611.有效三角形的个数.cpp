#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=611 lang=cpp
 *
 * [611] 有效三角形的个数
 */

// @lc code=start
class Solution {
   public:
    int triangleNumber(vector<int>& nums) {
        int total = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                int l = 0, r = j - 1;
                while (l < r) {
                    int mid = l + (r - l) / 2;
                    if (nums[mid] + nums[j] > nums[i])
                        r = mid;
                    else
                        l = mid + 1;
                }
                if (l == r && nums[l] + nums[j] > nums[i])
                    total += j - l;
            }
        }
        return total;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = getArray(str);
        print(Solution().triangleNumber(arr));
    }
}