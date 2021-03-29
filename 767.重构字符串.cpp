#include "LeetCode.h"
#include <queue>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        int dict[26] = {0};
        for(auto i:s)dict[i-'a']++;
        //check if valid
        int maxValidLength = (s.size()+1)/2;
        for(int i=0;i<26;i++){
            if(dict[i]>maxValidLength)return "";
        }
        //valid, rebuild string
        string str;
        //priority queue by weight from dict
        auto cmp = [&](const char &a,const char &b){
            return dict[a-'a'] < dict[b-'a'];
        };
        priority_queue<char,vector<char>,decltype(cmp)> q{cmp};
        for(int i=0;i<26;i++)if(dict[i])q.push((char)i+'a');
        //rebuild, each epoch choose the biggest two
        char cur[2]={'\0'};
        while(q.size()>1){
            for(int i=0;i<2;i++){
                cur[i] = q.top();q.pop();
                str.push_back(cur[i]);
            }

            for(int i=0;i<2;i++){
                if(--dict[cur[i]-'a'])q.push(cur[i]);
            }
        }

        return q.size()?str+q.top():str;
    }
};

int main(){
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        in>>str;
        if(str.size()&&str[0]=='"')str=str.substr(1,str.size()-2);
        printf("结果是%s\n",Solution().reorganizeString(str).c_str());
    }
    
}