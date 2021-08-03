#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=679 lang=cpp
 *
 * [679] 24 点游戏
 */

// @lc code=start
class Solution {
    bool equal(double a, double b) {
        return abs(a - b) < 1e-7;
    }
    bool isTwentyFour(vector<double> cards) {
        if(cards.size()==1){
            return equal(cards[0],24.0);
        }
        for(int i=0;i<cards.size();i++){
            for(int j=i+1;j<cards.size();j++){
                double first=cards[i],second=cards[j];
                vector<double> temp;
                for(int k=0;k<cards.size();k++){
                    if(k!=i&&k!=j)temp.push_back(cards[k]);
                }
                // 加法
                temp.push_back(first+second);
                if(isTwentyFour(temp))return true;
                // 减法
                temp.back()=first-second;
                if(isTwentyFour(temp))return true;
                temp.back()=second-first;
                if(isTwentyFour(temp))return true;
                // 乘法
                temp.back()=first*second;
                if(isTwentyFour(temp))return true;
                // 除法
                if(!equal(first,0)){
                    temp.back()=second/first;
                    if(isTwentyFour(temp))return true;
                }
                if(!equal(second,0)){
                    temp.back()=first/second;
                    if(isTwentyFour(temp))return true;
                }
            }
        }
        return false;
    }

   public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> temp;
        for(int i:cards)temp.push_back((double)i);
        return isTwentyFour(temp);
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = getArray(str);
        print(Solution().judgePoint24(arr));
    }
}