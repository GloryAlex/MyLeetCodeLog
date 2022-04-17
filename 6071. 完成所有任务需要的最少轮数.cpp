#include "lib/leetcode.h"
using namespace std;

class Solution {
   public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> taskCount;
        for (int i : tasks) taskCount[i]++;

        int total = 0;
        for (auto [_, cnt] : taskCount) {
            if (cnt == 1) return -1;
            switch (cnt % 3) {
                case 0:
                    total += cnt / 3;
                    break;
                case 1:
                    total += (cnt - 4) / 3 + 2;
                    break;
                case 2:
                    total += (cnt - 2) / 3 + 1;
                    break;
            }
        }
        return total;
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto t = j.get<vector<int>>();
        print(Solution().minimumRounds(t));
    }
}