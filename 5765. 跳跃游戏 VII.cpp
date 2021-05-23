#include "LeetCode.h"
using namespace std;

class Solution {
   public:
    bool canReach(string s, int minJump, int maxJump) {
        int length=s.size();
        if(s[length-1]!='0')return false;

        set<int> notVisit;
        for(int i=0;i<length;i++)if(s[i]=='0')notVisit.insert(i);

        queue<int> accessPositions;
        accessPositions.push(0);
        while(!accessPositions.empty()){
            int cur = accessPositions.front();
            accessPositions.pop();
            //在树中二分搜索
            int left=cur+minJump;
            int right=min(cur+maxJump,length-1);
            auto it = notVisit.lower_bound(left);
            while(it!=notVisit.end()&&*it<=right){
                accessPositions.push(*it);
                it = notVisit.erase(it);
            }
        }
        return !notVisit.count(length-1);
        
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        int m, n;
        in >> str >> m >> n;
        str = getString(str);
        print(Solution().canReach(str, m, n));
    }
}