#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=2024 lang=cpp
 *
 * [2024] 考试的最大困扰度
 */

// @lc code=start
class Solution {
    int maxConsecutiveAnswerByChar(string& testString, int tolerance, char target) {
        long maxLen = 0,countWrong=0;

        for (auto l=testString.begin(),r=l; r < testString.end(); ++r) {
            countWrong += (*r!=target);
            while(countWrong>tolerance){
                countWrong -= (*l++!=target);
            }
            maxLen = max(maxLen, (r - l) + 1);
        }

        return (int)maxLen;
    }

   public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(
            maxConsecutiveAnswerByChar(answerKey,k,'T'),
            maxConsecutiveAnswerByChar(answerKey,k,'F')
        );
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto key = j.get<string>();
        int k;
        in >> k >> ws;
        print(Solution().maxConsecutiveAnswers(key, k));
    }
}