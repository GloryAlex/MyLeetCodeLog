#include "lib/leetcode.h"
using namespace std;

class Solution {
   public:
    //    二分解法
    // vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries)
    // {
    //     vector<int> candles;
    //     unordered_map<int, int> preDisks;
    //     // 预处理所有蜡烛的位置以及前面的盘子数
    //     int sum = 0;
    //     for (int i = 0; i < s.size(); i++) {
    //         if (s[i] == '*') {
    //             sum++;
    //         } else {
    //             candles.push_back(i);
    //             preDisks[i] = sum;
    //         }
    //     }

    //     vector<int> res;
    //     for (const auto& query : queries) {
    //         int left = query[0], right = query[1];

    //         auto realLeft = lower_bound(candles.begin(), candles.end(),
    //         left); if (realLeft == candles.end()) {
    //             res.push_back(0);
    //             continue;
    //         }
    //         auto realRight = upper_bound(candles.begin(), candles.end(),
    //         right); if (realRight == candles.begin() || *(realRight - 1) >
    //         right) {
    //             res.push_back(0);
    //             continue;
    //         }
    //         realRight--;

    //         res.push_back(realLeft < realRight
    //                           ? preDisks[*realRight] - preDisks[*realLeft]
    //                           : 0);
    //     }
    //     return res;
    // }
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        auto LeftClosedCandies = vector<int>(s.size());
        auto RightClosedCandies = vector<int>(s.size());
        auto preDisks = unordered_map<int, int>();

        for (int i = 0, sum = 0, candlePosition = -1; i < s.size(); i++) {
            if (s[i] == '*') {
                sum++;
            } else {
                candlePosition = i;
                preDisks[candlePosition] = sum;
            }

            LeftClosedCandies[i] = candlePosition;
        }

        for (int i = (int)s.size() - 1, candlePosition = -1; i >= 0; i--) {
            if (s[i] == '|') {
                candlePosition = i;
            }

            RightClosedCandies[i] = candlePosition;
        }

        auto res = vector<int>();
        for(const auto& query:queries){
            int left=RightClosedCandies[query[0]],right=LeftClosedCandies[query[1]];
            if(left!=-1&&right!=-1&&left<right){
                res.push_back(preDisks[right]-preDisks[left]);
            }else{
                res.push_back(0);
            }
        }
        return res;
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto s = j.get<string>();
        in >> j >> ws;
        auto q = j.get<vector<vector<int>>>();
        print(Solution().platesBetweenCandles(s, q));
    }
}