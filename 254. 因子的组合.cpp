#include "LeetCode.h"
using namespace std;

class Solution
{
    vector<vector<int>> getAllFactors(int minFactory,int n)
    {
        vector<vector<int>> allFactors;
        for(int i=minFactory,end=sqrt(n);i<=end;i++){
            if(n%i==0){
                allFactors.push_back({i,n/i});
                for(auto& factors:getAllFactors(i,n/i)){
                    vector<int> factorsBeginWithI = vector<int>{i};
                    factorsBeginWithI.insert(factorsBeginWithI.end(),factors.begin(),factors.end());
                    allFactors.push_back(factorsBeginWithI);
                }
            }
        }
        return allFactors;
    }
public:
    vector<vector<int>> getFactors(int n)
    {
        return getAllFactors(2,n);
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        int n;
        in >> n;
        print(Solution().getFactors(n));
    }
}