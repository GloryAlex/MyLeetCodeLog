#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=658 lang=cpp
 *
 * [658] 找到 K 个最接近的元素
 */

// @lc code=start
class Solution {
   public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        if (pos>=arr.size()||pos > 0 && abs(arr[pos - 1] - x) <= abs(arr[pos] - x)) pos--;
        int i = pos, j = pos + 1;
        vector<int> result(k);
        result.resize(0);
        while (i >= 0 && j < arr.size() && result.size() < k) {
            int curNearestValue;
            if (abs(arr[i] - x) <= abs(arr[j] - x)) {
                curNearestValue = arr[i];
                i--;
            } else {
                curNearestValue = arr[j];
                j++;
            }
            result.emplace_back(curNearestValue);
        }
        while (i >= 0 && result.size() < k) result.emplace_back(arr[i--]);
        while (j < arr.size() && result.size() < k) result.emplace_back(arr[j++]);
        sort(result.begin(), result.end());
        return result;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        int k, x;
        in >> str >> k >> x;
        auto arr = getArray(str);
        print(Solution().findClosestElements(arr, k, x));
    }
}