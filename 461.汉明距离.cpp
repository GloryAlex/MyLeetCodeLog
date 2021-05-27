#include "LeetCode.h"
using namespace std;

/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
   public:
    int hammingDistance(int x, int y) {
        int diff = x^y;
        int total=0;
        while(diff){
            diff&=(diff-1);
            total++;
        }
        return total;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        int a, b;
        in >> a >> b;
        cout << Solution().hammingDistance(a, b);
    }
}
