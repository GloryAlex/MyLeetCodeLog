#include "lib/leetcode.h"
using namespace std;

class Solution {
   public:
    int countCollisions(string directions) {
        // 只有出现了 RL 或者 RS 或者 SL 才会发生碰撞
        queue<pair<int,int>> q;
        int n=directions.size();
        for(int i=0;i<n-1;i++){
            if(directions[i]=='R'){
                if(directions[i+1]=='L'||directions[i+1]=='S')q.push({i,i+1});
            }else if(directions[i]=='S'&&directions[i+1]=='L')q.push({i,i+1});
        }

        int total=0;
        while(!q.empty()){
            auto [l,r]=q.front();
            q.pop();

            if(directions[l]!='S'){
                directions[l]='S';
                total++;
            }
            if(directions[r]!='S'){
                directions[r]='S';
                total++;
            }

            if(l>0&&directions[l-1]=='R')q.push({l-1,l});
            if(r<n-1&&directions[r+1]=='L')q.push({r,r+1});
        }

        return total;
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto s = j.get<string>();
        cout << Solution().countCollisions(s) << endl;
    }
}