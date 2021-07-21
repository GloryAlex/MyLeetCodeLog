#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=593 lang=cpp
 *
 * [593] 有效的正方形
 */

// @lc code=start
class Solution {
   public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        auto dict = unordered_set<long long>({getLengthSquare(p1, p2),
                                              getLengthSquare(p1, p3),
                                              getLengthSquare(p1, p4),
                                              getLengthSquare(p2, p3),
                                              getLengthSquare(p2, p4),
                                              getLengthSquare(p3, p4)});
        return !dict.count(0) && dict.size() == 2;
    }
    long long getLengthSquare(vector<int>& p1, vector<int>& p2) {
        return (p2[0] - p1[0]) * (p2[0] - p1[0]) + (p2[1] - p1[1]) * (p2[1] - p1[1]);
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        vector<vector<int>> arr;
        for (int i = 0; i < 4; i++) {
            string s;
            in >> s;
            arr.push_back(getArray(s));
        }
        print(Solution().validSquare(arr[0], arr[1], arr[2], arr[3]));
    }
}