#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=780 lang=cpp
 *
 * [780] 到达终点
 */

// @lc code=start
class Solution {
   public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if (tx > sx && ty > sy && tx != ty) {
            if (tx > ty) {
                return reachingPoints(sx, sy, tx % ty, ty);
            } else {
                return reachingPoints(sx, sy, tx, ty % tx);
            }
        }

        if (tx == sx && ty == sy) {
            return true;
        } else if (tx == sx) {
            return sy < ty && (ty - sy) % tx == 0;
        } else if (ty == sy) {
            return sx < tx && (tx - sx) % ty == 0;
        } else {
            return false;
        }
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        int sx, sy, tx, ty;
        in >> sx >> sy >> tx >> ty >> ws;
        print(Solution().reachingPoints(sx, sy, tx, ty));
    }
}