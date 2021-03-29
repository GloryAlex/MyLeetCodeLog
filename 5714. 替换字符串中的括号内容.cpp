#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    string evaluate(string s, vector<vector<string>> &knowledge)
    {
        unordered_map<string,string> dict;
        for(const auto& i:knowledge)dict[i[0]]=i[1];

        string ret;
        for(int i=0;i<s.size();){
            if(s[i]=='('){
                //转换
                int j=i+1;
                while(j<s.size()&&s[j]!=')')j++;
                string temp=s.substr(i+1,j-i-1);
                ret+=dict.count(temp)?dict[temp]:"?";

                i=j+1;
            }else ret.push_back(s[i++]);
        }
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
        auto s = getString(str);
        in >> str;
        auto know = getStringMatrix(str);
        cout << Solution().evaluate(s, know) << endl;
    }
}