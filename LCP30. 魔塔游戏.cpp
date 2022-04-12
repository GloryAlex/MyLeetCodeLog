#include "lib/leetcode.h"
using namespace std;

class Solution {
    const int NO_SOLUTION = -1;

   public:
    int magicTower(vector<int>& effects) {
        if (accumulate(effects.begin(), effects.end(), 0LL) < 0) {
            return NO_SOLUTION;
        }

        priority_queue<int, vector<int>, greater<int>> orderedDamages;
        long long lifePoint = 1;

        int countShift = 0;
        for (int effect : effects) {
            if (effect < 0) orderedDamages.push(effect);

            lifePoint += effect;
            if (lifePoint <= 0) {
                lifePoint -= orderedDamages.top();
                orderedDamages.pop();
                countShift++;
            }
        }
        return countShift;
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto arr = j.get<vector<int>>();
        print(Solution().magicTower(arr));
    }
}