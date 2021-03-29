#include "LeetCode.h"
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        int banR=0,banD=0;
        int countR=0,countD=0;
        queue<char> q;
        for(char i:senate){
            q.push(i);
            if(i=='R')countR++;
            else countD++;
        }

        while(countR && countD){
            char cur = q.front();q.pop();
            if(cur=='R'){
                if(!banR){banD++;q.push(cur);}
                else {banR--;countR--;}
            }else{
                if(!banD){banR++;q.push(cur);}
                else {banD--;countD--;}
            }
        }

        return countR?"Radiant":"Dire";
    }
};

int main()
{
    ifstream in("input");
    while(!in.eof())
    {
        string str;
        in>>str;
        str=str.substr(1,str.size()-2);
        print(Solution().predictPartyVictory(str));
    }
}