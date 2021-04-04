#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>> &logs, int k)
    {
        unordered_map<int,unordered_set<int>> dict;
        for(const auto& log:logs){
            dict[log[0]].insert(log[1]);
        }
        vector<int> res = vector<int>(k);
        for(const auto& i:dict){
            res[(int)i.second.size()-1]++;
        }
        return res;
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        in >> str;
        auto arr = getMatrix(str);
        int k;
        in >> k;
        print(Solution().findingUsersActiveMinutes(arr, k));
    }
}