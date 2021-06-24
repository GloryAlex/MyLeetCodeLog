#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
    struct LetterDictionary {
       private:
        vector<int> freq = vector<int>(26);

       public:
        void insert(char i) { freq[i - 'a']++; }
        void remove(char i) { freq[i - 'a']--; }
        bool operator==(const Solution::LetterDictionary& b) const {
            return this->freq == b.freq;
        }
    };

   public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size()<p.size())return {};
        
        LetterDictionary sLetters, pLetters;
        for (char i : p) pLetters.insert(i);

        vector<int> result;
        int len = p.size();
        for (int i = 0; i < len; i++) sLetters.insert(s[i]);
        for (int i = len; i < s.size(); i++) {
            if (sLetters == pLetters) result.push_back(i - len);
            sLetters.insert(s[i]);
            sLetters.remove(s[i - len]);
        }
        if (sLetters == pLetters) result.push_back(s.size() - len);
        return result;
    }
};
// @lc code=end
int main() {
    ifstream in("input");
    while (!in.eof()) {
        string s, p;
        in >> s >> p;
        print(Solution().findAnagrams(s, p));
    }
}
