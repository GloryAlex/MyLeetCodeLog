#include "lib/leetcode.h"
using namespace std;

class Solution {
   public:
    string digitSum(string s, int k) {
        if (s.size() <= k) return s;
        string res;
        for (int i = 0; i < s.size();) {
            int j = 0;
            int temp = 0;
            while (i + j < s.size() && j < k) {
                temp += s[i + j] - '0';
                j++;
            }
            res += to_string(temp);
            i += j;
        }
        return digitSum(res, k);
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto s = j.get<string>();
        int k;
        in >> k >> ws;
        print(Solution().digitSum(s, k));
    }
}