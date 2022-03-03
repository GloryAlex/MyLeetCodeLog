#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */

// @lc code=start
class Solution {
   public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        auto arr = vector<int>(n + 1);
        for (const auto& booking : bookings) {
            int l = booking[0]-1, r = booking[1]-1, seats = booking[2];
            arr[l] += seats;
            arr[r + 1] -= seats;
        }
        // 从差分数组还原答案
        for (int i = 1; i < n; i++) {
            arr[i]+=arr[i-1];
        }
        arr.resize(n);
        return arr;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        vector<vector<int>> bookings = j.get<vector<vector<int>>>();
        int n;
        in >> n >> ws;
        print(Solution().corpFlightBookings(bookings, n));
    }
}