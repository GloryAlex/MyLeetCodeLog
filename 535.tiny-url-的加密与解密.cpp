#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=535 lang=cpp
 *
 * [535] TinyURL 的加密与解密
 */

// @lc code=start
class Solution {
    unordered_map<int,string> dict;
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        int key=rand();
        while(dict.count(key))key=rand();
        dict[key]=longUrl;
        return to_string(key);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int key=stoi(shortUrl);
        return dict[key];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
// @lc code=end

