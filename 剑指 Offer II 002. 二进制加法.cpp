#include "lib/leetcode.h"
using namespace std;

class Solution {
   public:
    string addBinary(string a, string b) {
        string result = "";
        int addOn = 0;

        for (auto i = a.rbegin(), j = b.rbegin();
             i != a.rend() || j != b.rend();) {
            int cur = (i == a.rend() ? 0 : (*i++) - '0') +
                      (j == b.rend() ? 0 : (*j++) - '0') + addOn;

            if (cur >= 2) {
                addOn = 1;
                cur -= 2;
            } else {
                addOn = 0;
            }
            result.push_back(cur + '0');
        }

        if (addOn) result.push_back('1');
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        string a = j.get<string>();
        in >> j >> ws;
        string b = j.get<string>();
        cout << Solution().addBinary(a, b) << endl;
    }
}