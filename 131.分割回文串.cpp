#include "LeetCode.h"
using namespace std;

class Solution
{
    vector<vector<string>> ret;
    vector<vector<int>> isPalidrome;
    vector<string> ans;
    int n;
    void dfs(const string&s ,int cur){
        if(cur==n){
            ret.push_back(ans);
            return;
        }
        for(int i=cur;i<n;i++){
            if(isPalidrome[cur][i]){
                ans.push_back(string(s.begin()+cur,s.begin()+i+1));
                dfs(s,i+1);
                ans.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s)
    {
        n = s.size();
        ret=vector<vector<string>>();
        isPalidrome = vector<vector<int>>(n, vector<int>(n,true));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                isPalidrome[i][j]=(s[i]==s[j] && isPalidrome[i+1][j-1]);
            }
        }
        dfs(s,0);
        return ret;
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
        print(Solution().partition(str));
    }
}