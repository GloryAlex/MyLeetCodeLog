#include "LeetCode.h"
/*
 * @lc app=leetcode.cn id=599 lang=cpp
 *
 * [599] 两个列表的最小索引总和
 */

// @lc code=start
class Solution {
   public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        auto result     = vector<string>();
        auto allList1   = unordered_map<string, int>();
        int minIndexSum = list1.size() + list2.size();
        for (int i = 0; i < list1.size(); i++) {
            allList1[list1[i]] = i;
        }
        for (int i = 0; i < list2.size(); i++) {
            if (allList1.count(list2[i])) {
                int curIndexSum = allList1[list2[i]] + i;
                if (curIndexSum < minIndexSum) {
                    result = {list2[i]};
                    minIndexSum=curIndexSum;
                } else if (curIndexSum == minIndexSum) {
                    result.emplace_back(list2[i]);
                }
            }
        }
        return result;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string s1, s2;
        in >> s1 >> s2;
        auto list1 = getStringArray(s1);
        auto list2 = getStringArray(s2);
        print(Solution().findRestaurant(list1, list2));
    }
}