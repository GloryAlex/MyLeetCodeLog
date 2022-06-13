#include "lib/leetcode.h"
using namespace std;

class Solution {
   public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        auto dict = unordered_map<int, int>();
        stack<int> s;
        for (int i = (int)nums2.size() - 1; i >= 0; i--) {
            while (!s.empty() && s.top() < nums2[i]) s.pop();
            dict[nums2[i]] = s.empty() ? -1 : s.top();

            s.push(nums2[i]);
        }
        auto res = nums1;
        for (int i = 0; i < res.size(); i++) {
            res[i] = dict[nums1[i]];
        }
        return res;
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto arr1 = j.get<vector<int>>();
        in >> j >> ws;
        auto arr2 = j.get<vector<int>>();
        print(Solution().nextGreaterElement(arr1, arr2));
    }
}