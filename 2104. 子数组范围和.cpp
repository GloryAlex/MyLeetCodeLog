#include "lib/leetcode.h"
using namespace std;

class Solution {
   public:
    long long subArrayRanges(vector<int>& nums) {
        long long res = 0;
        for (int i = 0; i < nums.size(); i++) {
            int maxElement = INT_MAX, minElement = INT_MIN;
            for (int j = i; j >= 0; j--) {
                maxElement = max(maxElement, nums[j]);
                minElement = min(minElement, nums[j]);
                res += maxElement - minElement;
            }
        }
        return res;
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto nums = j.get<vector<int>>();
    }
}