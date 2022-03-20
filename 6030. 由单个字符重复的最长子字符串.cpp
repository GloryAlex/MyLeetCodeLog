#include "lib/leetcode.h"
using namespace std;

class Solution {
    struct Node{
        int idx;
        char val;
        bool operator<(const Node b)const{
            return idx<b.idx;
        }
    };
   public:
    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {
        reverse(queryCharacters.begin(),queryCharacters.end());
        int n=s.size();
        auto findLongestRepeat = [&](){
            int total=0;
            for(int i=0;i<n;){
                int j=i;
                while(i<n && s[i]==s[j])i++;
                total=max(total,i-j);
            }
            return total;
        };

        vector<int> arr;
        for (auto i:queryIndices) {
            s[i]=queryCharacters.back();
            queryCharacters.pop_back();
            arr.push_back(findLongestRepeat());
        }
        return arr;
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto s = j.get<string>();
        in >> j >> ws;
        auto str = j.get<string>();
        in >> j >> ws;
        auto arr = j.get<vector<int>>();
        print(Solution().longestRepeating(s, str, arr));
    }
}