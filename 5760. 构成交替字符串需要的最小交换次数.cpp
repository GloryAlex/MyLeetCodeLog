#include "LeetCode.h"
using namespace std;
class Solution {
    int getDifferent(string& s, string& compare) {
        int oneDiff = 0, zeroDiff = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != compare[i]) {
                if (s[i] == '0')
                    zeroDiff++;
                else
                    oneDiff++;
            }
        }
        return oneDiff == zeroDiff ? oneDiff : -1;
    }

   public:
    int minSwaps(string s) {
        string one = s, zero = s;
        for (int i = 0; i < one.size(); i++) {
            one[i] = (i & 1) ? '1' : '0';
            zero[i] = (i & 1) ? '0' : '1';
        }
        int onediff = getDifferent(s, one);
        int zerodiff = getDifferent(s, zero);
        if (onediff != -1 && zerodiff != -1) return min(onediff, zerodiff);
        if (onediff == -1)
            return zerodiff;
        else
            return onediff;
    }
};
int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        str = getString(str);
        cout << Solution().minSwaps(str) << endl;
    }
}