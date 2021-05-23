#include "LeetCode.h"
using namespace std;

int rand7() { return 1 + rand() % 7; }

/*
 * @lc app=leetcode.cn id=470 lang=cpp
 *
 * [470] 用 Rand7() 实现 Rand10()
 */

// @lc code=start
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
   public:
    int rand10() {
        int row, col, index;
        do {
            row = rand7();
            col = rand7();
            index = (row - 1) * 7 + col;
        } while (index > 40);
        return 1 + (index - 1) % 10;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    srand((unsigned)time(NULL));
    while (!in.eof()) {
        int n;
        in >> n;
        vector<int> ret;
        vector<int> freq(10);
        for (int _ = 0; _ < n; _++) {
            ret.push_back(Solution().rand10());
            freq[ret.back() - 1]++;
        }
        printf("+-----+--------+\n");
        printf("| num |  freq  |\n");
        for (int i = 0; i < freq.size(); i++) {
            printf("|%5d|%.5lf%%|\n", i + 1, (double)freq[i] / n);
        }
        printf("+-----+--------+\n");
    }
}