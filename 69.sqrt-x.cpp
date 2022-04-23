#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
   public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        long long l = 1, r = x / 2 + 1;
        while (l < r) {
            auto mid = (r - l) / 2 + l;
            if (mid * mid < x)
                l = mid + 1;
            else
                r = mid;
        }
        return l * l == x ? l : l - 1;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        int x;
        in >> x >> ws;
        cout << Solution().mySqrt(x) << endl;
    }
}