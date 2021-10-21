#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lc code=start
class Solution {
   public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int i = 0, j = (int)letters.size() - 1;
        while (i < j) {
            int mid = (i + j) / 2;
            if (letters[mid] <= target)
                i = mid + 1;
            else
                j = mid;
        }
        if (letters[i] > target)
            return letters[i];
        else
            return letters[0];
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = getStringArray(str);
        in >> str;
        char target = str[1];
        vector<char> letters;
        for (auto i : arr) {
            letters.push_back(i[0]);
        }
        cout << (Solution().nextGreatestLetter(letters, target)) << endl;
    }
}