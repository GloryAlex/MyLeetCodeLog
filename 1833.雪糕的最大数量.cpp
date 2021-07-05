#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=1833 lang=cpp
 *
 * [1833] 雪糕的最大数量
 */

// @lc code=start
class Solution {
   public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int totalNums = 0,totalPrice=0;
        for(int i:costs){
            totalPrice+=i;
            if(totalPrice<=coins)totalNums++;
            else break;
        }
        return totalNums;
    }
};
// @lc code=end
int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        int coin;
        in >> str >> coin;
        auto arr = getArray(str);
        print(Solution().maxIceCream(arr, coin));
    }
}
