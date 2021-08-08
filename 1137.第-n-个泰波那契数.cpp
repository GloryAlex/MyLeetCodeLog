#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=1137 lang=cpp
 *
 * [1137] 第 N 个泰波那契数
 */

// @lc code=start
class Solution {
    static unordered_map<int, int> dict;

   public:
    int tribonacci(int n) {
        if (dict.count(n))
            return dict[n];
        else
            return dict[n] = tribonacci(n - 1) + tribonacci(n - 2) +
                             tribonacci(n - 3);
    }
};
unordered_map<int, int> Solution::dict = {{0, 0}, {1, 1}, {2, 1}};
// @lc code=end
int main() {
    ifstream in("input");
    while (!in.eof()) {
        int n;
        in >> n;
        print(Solution().tribonacci(n));
    }
}