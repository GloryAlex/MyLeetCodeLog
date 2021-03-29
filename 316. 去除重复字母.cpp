#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        vector<int> stack;
        vector<int> lastPosition(26),hasIt(26);
        for(auto i=0;i<s.size();i++){
            lastPosition[s[i]-'a']=i;
        }

        for(int i=0;i<s.size();i++){
            int cur = s[i] - 'a';
            if(hasIt[cur])continue;
            while(stack.size() && lastPosition[stack.back()]>i && stack.back()>cur){
                hasIt[stack.back()]=0;
                stack.pop_back();
            }
            stack.push_back(cur);
            hasIt[cur]=true;
        }

        s.resize(0);
        for(char i:stack)s.push_back(i+'a');
        return s;
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        in >> str;
        str = str.substr(1, str.size() - 2);
        print(Solution().removeDuplicateLetters(str));
    }
}