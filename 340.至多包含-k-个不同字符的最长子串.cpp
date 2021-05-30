#include "LeetCode.h"
using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) return 0;
        unordered_map<char, int> dict;
        long maxLength = 0;
        //双指针求解最大值
        for (auto i = s.begin(), j = s.begin();; j++) {
            for (; j != s.end(); j++) {
                dict[*j]++;
                if (dict.size() > k) break;
            }
            maxLength = max(maxLength, j - i);
            for (; i != j && dict.size() > k; i++) {
                if ((--dict[*i]) == 0) dict.erase(*i);
            }
            if (j == s.end()) break;
        }
        return (int)maxLength;
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        int k;
        in >> str >> k;
        str = getString(str);
        cout << Solution().lengthOfLongestSubstringKDistinct(str, k) << endl;
    }
}