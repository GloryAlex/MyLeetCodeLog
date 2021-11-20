#include "LeetCode.h"
using namespace std;

class Solution
{
private:
    const int NO_ANS = -1;
    inline bool oneWordDiff(const string &a, const string &b)
    {
        int diff = 0;
        for (int i = 0; i < a.size() && diff <= 1; i++)
        {
            if (a[i] != b[i])
                diff++;
        }
        return diff == 1;
    }

public:
    int minMutation(string start, string end, vector<string> &bank)
    {
        if(start == end)return 0;

        int length=bank.size();
        unordered_map<string,int> id;
        queue<int> q;

        for(int i=0;i<length;i++){
            id[bank[i]]=i;
            if(oneWordDiff(bank[i],start))q.push(i);
        }

        vector<int> hasVisited(bank.size());

        int endId;
        if(!id.count(end))return NO_ANS;
        else endId=id[end];

        int stepNums = 1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                if(q.front()==endId)return stepNums;

                int curId = q.front();
                q.pop();

                if(hasVisited[curId])continue;
                else hasVisited[curId]=true;

                for(int i=0;i<length;i++){
                    if(!hasVisited[i] && oneWordDiff(bank[curId],bank[i]))
                        q.push(i);
                }
            }
            stepNums++;
        }
        return NO_ANS;
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string m, n;
        string str;
        in >> m >> n >> str;
        m = m.substr(1, m.size() - 2);
        n = n.substr(1, n.size() - 2);
        auto arr = getStringArray(str);
        print(Solution().minMutation(m, n, arr));
    }
}