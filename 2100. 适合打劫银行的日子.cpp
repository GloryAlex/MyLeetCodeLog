#include "lib/leetcode.h"
using namespace std;

class Solution {
   public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        auto increasing = vector<int>(security.size());
        auto decreasing = vector<int>(security.size());

        for (int i = 1; i < security.size(); i++) {
            decreasing[i] =
                security[i] <= security[i - 1] ? decreasing[i - 1] + 1 : 0;
        }
        for (int i = (int)security.size() - 2, accumulated = 0; i >= 0; i--) {
            increasing[i] =
                security[i] <= security[i + 1] ? increasing[i + 1] + 1 : 0;
        }

        auto days = vector<int>();
        for (int i = 0; i < security.size(); i++) {
            if (increasing[i] >= time && decreasing[i] >= time)
                days.push_back(i);
        }
        return days;
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto arr = j.get<vector<int>>();
        int time;
        in >> time >> ws;
        print(Solution().goodDaysToRobBank(arr, time));
    }
}