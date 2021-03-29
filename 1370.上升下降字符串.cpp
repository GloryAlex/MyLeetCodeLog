#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string sortString(string s) {
        string ret;
        int dict[26] = {0};
        for(auto i:s)dict[i-'a']++;

        bool isBack = false;

        while (s.size()!=ret.size())
        {
            string temp;
            for(int i=0;i<26;i++){
                if(dict[i]){
                    temp.push_back(i+'a');
                    dict[i]--;
                }
            }
            if(isBack)reverse(temp.begin(),temp.end());

            isBack = !isBack;
            ret+=temp;
        }
        return ret;
    }
};

int main(void){
    string str;
    ifstream in("input");
    while(!in.eof()){
        in>>str;
        cout<<Solution().sortString(str)<<endl;
    }
}