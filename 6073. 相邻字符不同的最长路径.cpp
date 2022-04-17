#include "lib/leetcode.h"
using namespace std;

class Solution {
   public:
    int longestPath(vector<int>& parent, string s) {
        int n=s.size();
        vector<vector<int>> grid(n);
        for (int i = 1; i < parent.size(); i++) {
            if (parent[i] == -1) continue;
            grid[parent[i]].push_back(i);
        }
        
        int ans=0;
        function<int(int)> dfs;
        dfs = [&](int i) -> int {
            int maxChild=0,secondMax=0;
            for(int next:grid[i]){
                if(s[i]!=s[next]){
                    int nextLen = dfs(next);
                    if(nextLen>maxChild){
                        secondMax=maxChild;
                        maxChild=nextLen;
                    }else if(nextLen>secondMax){
                        secondMax=nextLen;
                    }
                }else{
                    dfs(next);
                }
            }
            ans=max(ans,maxChild+secondMax+1);
            return maxChild+1;
        };
        
        dfs(0);
        return ans;
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto p = j.get<vector<int>>();
        in >> j >> ws;
        auto s = j.get<string>();
        print(Solution().longestPath(p, s));
    }
}