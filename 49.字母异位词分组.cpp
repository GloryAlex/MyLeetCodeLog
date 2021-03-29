#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string,vector<string>> dict;
        string temp;

        for(int i=0,length=strs.size();i<length;i++){
            temp = strs[i];
            sort(temp.begin(),temp.end());

            dict[temp].push_back(move(strs[i]));
        }

        vector<vector<string>> ret;
        for(auto &i:dict)ret.push_back(move(i.second));
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
        auto arr = getStringArray(str);
        print(Solution().groupAnagrams(arr));
    }
}