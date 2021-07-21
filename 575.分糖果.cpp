#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=575 lang=cpp
 *
 * [575] 分糖果
 */

// @lc code=start
class Solution {
   public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> types;
        for(int i:candyType)types.insert(i);
        return min(types.size(),candyType.size()/2);
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = getArray(str);
        print(Solution().distributeCandies(arr));
    }
}