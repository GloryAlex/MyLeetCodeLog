#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=1846 lang=cpp
 *
 * [1846] 减小和重新排列数组后的最大元素
 */

// @lc code=start
class Solution {
   public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] > 1) arr[i] = arr[i - 1] + 1;
        }
        return arr.back();
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = getArray(str);
        print(Solution().maximumElementAfterDecrementingAndRearranging(arr));
    }
}