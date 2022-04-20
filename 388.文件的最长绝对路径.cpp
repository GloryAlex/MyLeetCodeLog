#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=388 lang=cpp
 *
 * [388] 文件的最长绝对路径
 */

// @lc code=start
class Solution {
   public:
    class Parser {
        string s;
        string::iterator it;

       public:
        class Token {
           private:
            int depth = 0;
            int length=0;
            bool isFile = false;

           public:
            void init() {
                *this = Token();
            }
            void add(char c) {
                switch (c) {
                    case '\t':
                        if (!length)
                            depth++;
                        else
                            length++;
                        break;
                    case '.':
                        isFile = true;
                    default:
                        length++;
                        break;
                }
            }
            int getDepth() { return depth; }
            int getLength() { return length; }
            bool isDir() { return !isFile; }
        };
        Parser(string s) {
            this->s = move(s);
            it = this->s.begin();
        }
        void skipEmpty() {
            while (it != s.end() && *it == '\n') it++;
        }
        Token next() {
            Token t;
            while (it != s.end() && *it != '\n') {
                t.add(*it++);
            }
            skipEmpty();
            return t;
        }
        bool hasNext() {
            return it != s.end();
        }
    };

   public:
    int lengthLongestPath(string input) {
        auto p = Parser(move(input));
        // {first: length, second: depth}
        auto s = stack<pair<int, int>>({{0, -1}});
        int longestLength = 0;
        while (p.hasNext()) {
            auto cur = p.next();
            while (s.top().second >= cur.getDepth()) {
                s.pop();
            }

            if (cur.isDir()) {
                s.push({s.top().first + cur.getLength(), cur.getDepth()});
            } else {
                longestLength =
                    max(longestLength,
                        cur.getDepth() + cur.getLength() + s.top().first);
            }
        }
        return longestLength;
    }
};
// @lc code=end
int main() {
    json j;
    ifstream in("input");
    while (!in.eof()) {
        in >> j >> ws;
        auto s = j.get<string>();
        print(Solution().lengthLongestPath(s));
    }
}
