#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=423 lang=cpp
 *
 * [423] 从英文中重建数字
 */

// @lc code=start
class Solution {
    //只能包含小写字母!
    struct LetterMap {
        int map[26] = {0};
        int& operator[](char letter) { return map[letter - 'a']; }
        LetterMap(const string& str) {
            for (char i : str) map[i - 'a']++;
        }
    };
    int removeAllFromIdentity(LetterMap& letters, char i, const string& s) {
        int nums = letters[i];
        for (char c : s) {
            letters[c] -= nums;
        }
        return nums;
    }

   public:
    string originalDigits(string s) {
        vector<string> englishNumebrs = {"zero",  "one",  "two", "three",
                                         "four",  "five", "six", "seven",
                                         "eight", "nine"};
        vector<unordered_map<char, string>> identities = {
            {{'z', "zero"},
             {'w', "two"},
             {'u', "four"},
             {'x', "six"},
             {'g', "eight"}},
            {{'o', "one"}, {'t', "three"}, {'f', "five"}, {'s', "seven"}},
            {{'i', "nine"}}};
        auto letters = LetterMap(s);
        auto resultForm = unordered_map<string, int>();
        for (auto& identity : identities) {
            for (const auto& [i, word] : identity) {
                resultForm[word] = removeAllFromIdentity(letters, i, word);
            }
        }
        string result;
        for (int i = 0; i < 10; i++)
            result.append(resultForm[englishNumebrs[i]], (char)(i + '0'));
        return result;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        str = getString(str);
        print(Solution().originalDigits(str));
    }
}