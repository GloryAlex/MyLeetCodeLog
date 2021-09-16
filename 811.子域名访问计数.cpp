#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=811 lang=cpp
 *
 * [811] 子域名访问计数
 */

 // @lc code=start
class Solution {
    string nextDomain(string str) {
        auto i = str.begin();
        while (i != str.end() - 1 && *i != '.')i++;
        return string(i + 1, str.end());
    }
    pair<int, string> getFreqAndDomain(string input) {
        auto i = input.begin();
        while (*i != ' ')i++;
        return { stoi(string(input.begin(),i))
            ,string(i + 1,input.end())
        };
    }
    vector<string> buildAns(unordered_map<string, int> dict) {
        vector<string> result;
        for (const auto [domain, freq] : dict) {
            result.push_back(to_string(freq) + " " + domain);
        }
        return result;
    }
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> dict;
        for (auto cpdoamin : cpdomains) {
            auto [freq, domain] = getFreqAndDomain(move(cpdoamin));
            while (!domain.empty()) {
                dict[domain] += freq;
                domain = nextDomain(domain);
            }
        }
        return buildAns(move(dict));
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        getline(in,str);
        auto arr = getStringArray(str);
        print(Solution().subdomainVisits(arr));
    }
}