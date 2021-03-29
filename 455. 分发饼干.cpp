#include "LeetCode.h"
#include <map>
using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int count = 0;
        for(int i=0,j=0;i<g.size()&&j<s.size();){
            if(g[i]<=s[j]){
                i++,j++,count++;
            }else{
                j++;
            }
        }
        return count;
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str, str2;
        in >> str >> str2;
        auto arr = getArray(str), arr2 = getArray(str2);
        cout << Solution().findContentChildren(arr, arr2) << endl;
    }
}