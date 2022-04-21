#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=824 lang=cpp
 *
 * [824] 山羊拉丁文
 */

// @lc code=start
class Solution {
   public:
    string toGoatLatin(string sentence) {
        stringstream in(sentence);
        string out;
        int aNums=1;
        auto goating = [](const string& s){
            unordered_set<char> dict={'a', 'e', 'i', 'o', 'u','A', 'E', 'I', 'O', 'U'};
            if(dict.count(s[0])){
                return s+"ma";
            }else{
                return string(s.begin()+1,s.end())+s[0]+"ma";
            }
        };

        while(!in.eof()){
            string cur;
            in>>cur>>ws;
            out += goating(cur)+string(aNums,'a') + ' ';

            aNums++;
        }

        if(!out.empty())out.pop_back();
        return out;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto s = j.get<string>();
        print(Solution().toGoatLatin(s));
    }
}