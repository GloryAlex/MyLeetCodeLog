#include <set>

#include "lib/leetcode.h"
using namespace std;

class Solution {
    long long accumulate(long long pre, long long end) {
        return (pre + end) * (end - pre + 1) / 2;
    }

   public:
    long long minimalKSum(vector<int>& nums, int k) {
        set<int> s;
        for(int i:nums)s.insert(i);
        nums=vector<int>(s.begin(),s.end());
        
        long long sum = 0;

        for (int i = 0; i < nums.size() && k > 0; i++) {
            int cur = nums[i], pre = (i == 0 ? 0 : nums[i - 1]);
            int end = min(pre  + k, cur - 1);
            if (pre <= end) {
                sum += accumulate(pre + 1, end);
                k -= (end - pre);
                // cout<<' ';
            }
        }
        if (k > 0) {
            int pre = nums.back() + 1;
            int end = pre + k;
            sum += accumulate(pre, end-1);
        }
        return sum;
    }
};
int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto arr = j.get<vector<int>>();
        int k;
        in >> k >> ws;
        print(Solution().minimalKSum(arr, k));
    }
}