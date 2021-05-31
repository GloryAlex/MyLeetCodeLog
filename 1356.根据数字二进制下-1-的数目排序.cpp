#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=1356 lang=cpp
 *
 * [1356] 根据数字二进制下 1 的数目排序
 */

// @lc code=start
class Solution {
    int getOneNums(int i) {
        int total = 0;
        while (i) {
            i &= (i - 1);
            total++;
        }
        return total;
    }

   public:
    vector<int> sortByBits(vector<int>& arr) {
        unordered_map<int, int> weights;
        for (int i : arr)
            if (!weights.count(i)) weights[i] = getOneNums(i);
        sort(arr.begin(), arr.end(), [&](const int& a, const int& b) {
            return weights[a] != weights[b] ? weights[a] < weights[b] : a < b;
        });
        return arr;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = getArray(str);
        print(Solution().sortByBits(arr));
    }
}