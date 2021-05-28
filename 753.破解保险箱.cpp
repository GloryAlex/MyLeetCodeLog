#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=753 lang=cpp
 *
 * [753] 破解保险箱
 */

// @lc code=start
class Solution {
   public:
   /**
    * TODO: 没有完全理解
    * 需要重做
    **/
    string crackSafe(int n, int k) {
        int kn_1 = pow(k, n - 1), kn = kn_1 * k;
        auto nums = vector<int>(kn_1, k - 1);
        auto str = string(n - 1 + kn, '0');
        for (int i = n - 1, node = 0; i < str.size(); i++) {
            str[i] = nums[node]-- + '0';
            node = node * k - (str[i - (n - 1)] - '0') * kn_1 + nums[node] + 1;
        }
        return str;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        int n, k;
        in >> n >> k;
        cout << Solution().crackSafe(n, k);
    }
}