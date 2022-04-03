#include "lib/leetcode.h"
using namespace std;

class Solution {
    struct leetCodePairHash {
       public:
        template <typename T, typename U>
        size_t operator()(const pair<T, U>& x) const {
            return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
        }
    };

   public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                       int k) {
        if (nums1.empty() || nums2.empty()) return {};
        int m = nums1.size(), n = nums2.size();
        unordered_set<pair<int, int>, leetCodePairHash> s;

        auto cmp = [&](const pair<int, int>& a, const pair<int, int>& b) {
            return nums1[a.first] + nums2[a.second] >
                   nums1[b.first] + nums2[b.second];
        };
        auto q = priority_queue<pair<int, int>, vector<pair<int, int>>,
                                decltype(cmp)>(cmp);
        auto isValid = [&](pair<int, int>& p) {
            return p.first < m && p.second < n;
        };
        q.push({0, 0});
        vector<vector<int>> res;
        while (res.size() < k && !q.empty()) {
            auto p = q.top();
            q.pop();

            res.push_back({nums1[p.first], nums2[p.second]});

            auto next1 = pair<int, int>{p.first + 1, p.second};
            auto next2 = pair<int, int>{p.first, p.second + 1};
            if (!s.count(next1) && isValid(next1)) {
                q.push(next1);
                s.insert(next1);
            }
            if (!s.count(next2) && isValid(next2)) {
                q.push(next2);
                s.insert(next2);
            }
        }
        return res;
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str1, str2;
        int k;
        in >> str1 >> str2 >> k;
        auto arr1 = getArray(str1);
        auto arr2 = getArray(str2);
        auto res = Solution().kSmallestPairs(arr1, arr2, k);
        print(res);
    }
}