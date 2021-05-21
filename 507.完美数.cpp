#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=507 lang=cpp
 *
 * [507] 完美数
 */

// @lc code=start
class Solution {
   public:
    bool checkPerfectNumber(int num) {
        if(num<6)return false;
        int total = 1;
        int sqrtOfNum = sqrt(num);
        if(sqrtOfNum*sqrtOfNum==num)total+=sqrtOfNum;
        else sqrtOfNum++;
        for(int i=2;i<sqrtOfNum;i++){
            if(num%i==0)total+=(i+num/i);
        }
        return total==num;
    }
};
// @lc code=end
int main() {
    ifstream in("input");
    while (!in.eof()) {
        int n;
        in >> n;
        print(Solution().checkPerfectNumber(n));
    }
}
