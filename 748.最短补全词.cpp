#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=748 lang=cpp
 *
 * [748] 最短补全词
 */

// @lc code=start
class Solution {
  class Dictionary {
   private:
    vector<int> dict = vector<int>(26);

   public:
    Dictionary(const string& str) {
      for (char i : str) {
        if (isalpha(i)) dict[tolower(i) - 'a']++;
      }
    }
    int& operator[](char i) { return dict[i - 'a']; }
    bool operator==(const Solution::Dictionary& b) const {
      for (int i = 0; i < 26; i++) {
        if (dict[i] != b.dict[i]) return false;
      }
      return true;
    }
    bool contains(const Solution::Dictionary& b) {
      for (int i = 0; i < 26; i++) {
        if (dict[i] < b.dict[i]) return false;
      }
      return true;
    }
  };

 public:
  string shortestCompletingWord(string licensePlate, vector<string>& words) {
      auto target = Dictionary(licensePlate);

      int minLength = INT_MAX;
      int minIndex=0;
      for(int i=0;i<words.size();i++){
        if(words[i].length()<minLength && Dictionary(words[i]).contains(target)){
            minLength=words[i].length();
            minIndex=i;
        }
      }
      return words[minIndex];
  }
};
// @lc code=end

int main() {
  ifstream in("input");
  while (!in.eof()) {
    string str, s2;
    in >> str >> s2;
    str = getString(str);
    auto words = getStringArray(s2);
    print(Solution().shortestCompletingWord(str, words));
  }
}