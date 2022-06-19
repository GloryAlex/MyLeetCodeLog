#include "lib/leetcode.h"
using namespace std;

class Solution {
   public:
    int longestSubsequence(string s, int k) {
        vector<int> order;
        for (int i = (int)s.size() - 1; i >= 0; i--)
            if (s[i] == '1') order.push_back(s.size() - i);

        int cnt = s.size() - order.size();
        long long sum = 0;
        for (int i : order) {
            sum += pow(2LL, i-1);
            if (sum > k)
                break;
            else
                cnt++;
        }
        return cnt;
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        int k;
        in >> j >> k >> ws;
        auto s = j.get<string>();
        print(Solution().longestSubsequence(s, k));
    }
}