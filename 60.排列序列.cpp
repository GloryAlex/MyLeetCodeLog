#include "LeetCode.h"
using namespace std;

class Solution
{
private:
    static unordered_map<int,int> fact;
    int fac(int i){
        if(fact.count(i))return fact[i];
        else return fact[i]=i*fac(i-1);
    }
public:
    string getPermutation(int n, int k)
    {
        string s = string("123456789").substr(0,n),ret="";
        
        k--;
        while(k){
            int i=k/fac(n-1);
            ret.push_back(s[i]);
            s.erase(s.begin()+i);

            k=k%fac(n-1);
            n--;
        }
        return ret+s;
    }
};
unordered_map<int,int> Solution::fact = {{0,1}};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        int n, k;
        in >> n >> k;
        cout << Solution().getPermutation(n, k) << endl;
    }
}