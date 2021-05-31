#include "LeetCode.h"
using namespace std;
class Solution {
    struct pair_hash {
        inline std::size_t operator()(const std::pair<int, int>& v) const {
            return v.first * 31 + v.second;
        }
    };

   public:
    bool isReflected(vector<vector<int>>& points) {
        unordered_set<pair<int, int>, pair_hash> dict;
        int left = INT_MAX, right = INT_MIN;
        for (const auto& point : points) {
            left = min(left, point[0]);
            right = max(right, point[0]);
            dict.insert({point[0], point[1]});
        }
        double mid = (left + right) / 2.0;
        int count = 0, target = points.size() / 2;
        for (auto [x, y] : dict) {
            int reflect = 2 * mid - x;
            if (!dict.count({reflect, y})) return false;
            if (++count > target) break;
        }
        return true;
    }
};
int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = getMatrix(str);
        print(Solution().isReflected(arr));
    }
}