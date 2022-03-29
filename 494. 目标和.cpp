#include "lib/leetcode.h"
using namespace std;

class Solution {
    struct leetCodePairHash {
       public:
        template <typename T, typename U>
        size_t operator()(const pair<T, U> &x) const {
            return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
        }
    };
    unordered_map<pair<int, int>, int, leetCodePairHash> dict;
    int dfs(vector<int> &nums, int target, int i, int sum) {
        if (dict.count({i, sum})) return dict[{i, sum}];
        if (i == nums.size()) {
            return dict[{i, sum}] = (sum == target);
        }
        return dict[{i, sum}] = dfs(nums, target, i + 1, sum + nums[i]) +
                                dfs(nums, target, i + 1, sum - nums[i]);
    }

   public:
    int findTargetSumWays(vector<int> &nums, int s) {
        dict = unordered_map<pair<int, int>, int, leetCodePairHash>();
        return dfs(nums, 0, 0, s);
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        int s;
        in >> str >> s >> ws;
        auto arr = getArray(str);
        print(Solution().findTargetSumWays(arr, s));
    }
}