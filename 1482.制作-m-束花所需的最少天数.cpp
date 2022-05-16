#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=1482 lang=cpp
 *
 * [1482] 制作 m 束花所需的最少天数
 */

// @lc code=start
class Solution {
   public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (bloomDay.size() < m * k) return -1;
        auto canMake = [&](int day) {
            int remain = m;
            for (int i = 0, j = 0;
                 remain > 0 && i < (int)bloomDay.size() - k + 1;) {
                for (j = 0; j < k; j++) {
                    if (bloomDay[i + j] > day) break;
                }
                if (j == k) {
                    remain--;
                    i += j;
                } else {
                    i += j + 1;
                }
            }
            return remain <= 0;
        };

        int l = 0, r = *max_element(bloomDay.begin(), bloomDay.end()) + 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (!canMake(mid))
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto arr = j.get<vector<int>>();
        int m, k;
        in >> m >> k >> ws;
        print(Solution().minDays(arr, m, k));
    }
}