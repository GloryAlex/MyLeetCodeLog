#include "lib/leetcode.h"
using namespace std;

class Solution {
   public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        auto getKth = [](int k, int size) {
            int len = (size - 1) / 2 + 1;
            if (k > (long long)pow(10LL, len - 1) * 9LL) {
                return -1LL;
            }

            auto res = (long long)pow(10LL, len - 1) + k - 1;
            auto temp = len * 2 == size ? res : res / 10;
            auto reve = 0LL;
            while (temp) {
                reve = reve * 10 + temp % 10;
                temp /= 10;
            }

            return res * (long long)pow(10LL, size / 2) + reve;
        };

        auto res = vector<long long>();
        res.reserve(queries.size());

        for (int i : queries) {
            res.push_back(getKth(i, intLength));
        }

        return res;
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto arr = j.get<vector<int>>();
        int n;
        in >> n >> ws;
        print(Solution().kthPalindrome(arr, n));
    }
}