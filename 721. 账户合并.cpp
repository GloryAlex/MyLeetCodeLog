#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    class JointCluster
    {
    public:
        vector<int> father;
        JointCluster(int i) : father(vector<int>(i, -1)) {}
        int find(int i)
        {
            return father[i] < 0 ? i : father[i] = find(father[i]);
        }
        void join(int x, int y)
        {
            x = find(x), y = find(y);
            if (x == y)
                return;

            if (father[x] <= father[y])
            {
                father[x] += father[y];
                father[y] = x;
            }
            else
            {
                father[y] += father[x];
                father[x] = y;
            }
        }
        vector<vector<int>> getAllClusters(void){
            unordered_map<int,vector<int>> dict;
            for(int i=0;i<father.size();i++){
                dict[find(i)].push_back(i);
            }
            vector<vector<int>> ret;
            for(auto i=dict.begin();i!=dict.end();i++){
                ret.push_back(i->second);
            }
            return ret;
        }
    };
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        unordered_map<string, int> id;
        unordered_map<string, string> name;

        vector<vector<string>::iterator> mails;

        int count = 0;
        for (auto &account : accounts)
        {
            for (int i = 1; i < account.size(); i++)
            {
                if (!id.count(account[i]))
                {
                    mails.push_back(account.begin()+i);
                    id[account[i]] = count++;
                    name[account[i]] = account[0];
                }
            }
        }

        JointCluster jCluster=JointCluster(count);
        for (const auto &account : accounts){
            int firstIndex = id[account[1]];
            for(auto i=account.begin()+2;i!=account.end();i++){
                int secondIndex=id[*i];
                jCluster.join(firstIndex,secondIndex);
            }
        }

        auto tempRet = jCluster.getAllClusters();
        vector<vector<string>> ret;
        for(auto account:tempRet){
            vector<string> temp(account.size());
            for(int i=0;i<account.size();i++){
                temp[i]=(*mails[account[i]]);
            }
            sort(temp.begin(),temp.end());

            ret.push_back({name[temp[0]]});
            ret.back().insert(ret.back().end(),temp.begin(),temp.end());
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
        auto account = getStringMatrix(str);
        print(Solution().accountsMerge(account));
    }
}