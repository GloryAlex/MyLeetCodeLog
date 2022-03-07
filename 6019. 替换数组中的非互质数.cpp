#include <list>

#include "lib/leetcode.h"
using namespace std;

class Solution {
   public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> s;
        for (int i : nums) {
            while (!s.empty() && gcd(i, s.back())!=1) {
                int val = s.back();
                s.pop_back();
                i = lcm(i, val);
            }
            s.push_back(i);
        }
        return s;
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto arr = j.get<vector<int>>();
        print(Solution().replaceNonCoprimes(arr));
    }
}