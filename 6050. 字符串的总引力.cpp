#include "lib/leetcode.h"
using namespace std;

class Solution {
   public:
    long long appealSum(string s) {
        long long res=0;
        for(int i=0;i<s.size();i++){
            unordered_set<char> d;
            for(int j=i;j<s.size();j++){
                d.insert(s[j]);
                res+=d.size();
            }
        }
        return res;
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto s = j.get<string>();
        print(Solution().appealSum(s));
    }
}