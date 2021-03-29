#include "LeetCode.h"

using namespace std;

class anotherSolution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> dict;
        for(auto i:tasks)dict[i]++;

        auto cmp = [&](char a,char b){
            return dict[a]<dict[b];
        };
        priority_queue<char,vector<char>,decltype(cmp)> q(cmp);

        for(auto [i,_]:dict)q.push(i);

        int totalTimeCost = 0;
        while(!dict.empty()){
            vector<char> tempStore;
            for(int i=0;i<=n && !dict.empty();i++){
                if(!q.empty()){
                    tempStore.push_back(q.top());
                    q.pop();
                    if(!--dict[tempStore[i]])dict.erase(tempStore[i]);
                }
                totalTimeCost++;
            }

            for(int i:tempStore){
                if(dict.count(i))q.push(i);
            }            
        }
        return totalTimeCost;
    }
    
};

class Solution{
public:
    int leastInterval(vector<char>& tasks, int n){
        int freq[26]={0};
        for(char i:tasks)freq[i-'A']++;

        int maxFreq = 0,maxCount=0;
        for(int i=0;i<26;i++){
            if(freq[i]>maxFreq){
                maxFreq=freq[i];
                maxCount=1;
            }else if(freq[i]==maxFreq){
                maxCount++;
            }else{
                //do nothing
            }
        }

        return max((maxFreq-1)*(n+1)+maxCount,(int)tasks.size());
    }
};

int main()
{
    ifstream in("input");
    while(!in.eof()){
        string str;
        int n;
        in>>str>>n;
        auto arr = getStringArray(str);
        vector<char> tasks;
        for(auto i:arr)tasks.push_back(i[0]);
        print(Solution().leastInterval(tasks,n));
    }
}