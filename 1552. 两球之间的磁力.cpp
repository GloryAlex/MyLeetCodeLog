#include "lib/leetcode.h"
using namespace std;

class Solution {
   public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        long l = 1, r = 1e9 + 1;
        auto isValidMinForce = [&](int force) {
            bool isExsit = true;
            for (int i = 1, prev = position[0]; i < m; i++) {
                auto it =
                    lower_bound(position.begin(), position.end(), prev + force);
                if (it == position.end()) {
                    isExsit = false;
                    break;
                } else {
                    prev = *it;
                }
            }
            return isExsit;
        };
        while (l < r) {
            int mid = l + (r - l) / 2;
            // 收缩边界
            if (isValidMinForce(mid)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l - 1;
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        int m;
        in >> j >> m >> ws;
        auto p = j.get<vector<int>>();
        print(Solution().maxDistance(p, m));
    }
}