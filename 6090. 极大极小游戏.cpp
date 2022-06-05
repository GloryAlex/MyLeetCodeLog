#include "lib/leetcode.h"
using namespace std;

class Solution {
   public:
    int minMaxGame(vector<int>& nums) {
        auto t = nums;
        while (t.size() != 1) {
            auto nt = vector<int>(t.size() / 2);
            for (int i = 0; i < t.size() / 2; i++) {
                if (i % 2) {
                    // 奇数
                    nt[i] = max(t[2 * i], t[2 * i + 1]);
                } else {
                    nt[i] = min(t[2 * i], t[2 * i + 1]);
                }
            }
            t = nt;
        }
        return t[0];
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto a = j.get<vector<int>>();
        print(Solution().minMaxGame(a));
    }
}