#include "LeetCode.h"
using namespace std;

class Solution {
 public:
  string nextPermutation(const string& input) {
    auto s = input;
    int i = s.size() - 2;
    for (; i >= 0; i--) {
      if (s[i] < s[i + 1]) break;
    }
    if (i >= 0) {
      int j = s.size() - 1;
      for (; j >= 0; j--) {
        if (s[i] < s[j]) break;
      }
      swap(s[i], s[j]);
    }
    reverse(s.begin() + i + 1, s.end());
    return s;
  }
  vector<string> permutation(string s) {
    sort(s.begin(), s.end());
    auto ret = vector<string>();
    ret.push_back(s);
    while (true) {
      s = nextPermutation(s);
      if (s == ret[0])
        break;
      else
        ret.push_back(s);
    }
    return ret;
  }
};
int main() {
  ifstream in("input");
  while (!in.eof()) {
    string str;
    in >> str;
    auto arr = getString(str);
    print(Solution().permutation(arr));
  }
}