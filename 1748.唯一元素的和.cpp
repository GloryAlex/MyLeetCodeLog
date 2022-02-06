#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=1748 lang=cpp
 *
 * [1748] 唯一元素的和
 */

// @lc code=start
class Solution {
   public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> elementCount;
        for (auto i : nums) {
            elementCount[i]++;
        }

        int sum = 0;
        for (auto [element, count] : elementCount) {
            if (count == 1) {
                sum += element;
            }
        }
        return sum;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    json j;
    int i = 0;
    while (!in.eof()) {
        in >> j >> ws;
        auto arr = j.get<vector<int>>();
        cout << Solution().sumOfUnique(arr) << endl;
    }
}