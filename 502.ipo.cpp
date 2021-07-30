#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=502 lang=cpp
 *
 * [502] IPO
 */

// @lc code=start
class Solution {
   public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        auto cmpCapacity   = [&](int i, int j) { return capital[i] > capital[j]; };
        auto cmpProfit     = [&](int i, int j) { return profits[i] < profits[j]; };
        auto capacityQueue = priority_queue<int, vector<int>, decltype(cmpCapacity)>(cmpCapacity);
        auto profitQueue   = priority_queue<int, vector<int>, decltype(cmpProfit)>(cmpProfit);
        for (int i = 0; i < capital.size(); i++) {
            if (capital[i] <= w)
                profitQueue.push(i);
            else
                capacityQueue.push(i);
        }
        while (k--) {
            if (profitQueue.empty()) break;
            w += profits[profitQueue.top()];
            profitQueue.pop();
            while (!capacityQueue.empty()) {
                if (capital[capacityQueue.top()] <= w) {
                    profitQueue.push(capacityQueue.top());
                    capacityQueue.pop();
                }else break;
            }
        }
        return w;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        int k, w;
        string s1, s2;
        in >> k >> w >> s1 >> s2;
        auto p = getArray(s1);
        auto q = getArray(s2);
        print(Solution().findMaximizedCapital(k, w, p, q));
    }
}