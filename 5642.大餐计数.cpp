#include "LeetCode.h"
#include <stdio.h>
using namespace std;

inline bool isPowerOf2(int n){
        return  n>0 && !(n&(n-1));
}
class Solution
{
const int MOD=1e9+7;  
public:
    int countPairs(vector<int> &deliciousness)
    {
        unordered_map<int,int> dict;
        vector<int> all2Powers;
        for(long long i=1;;i*=2){
            if(i>INT_MAX)break;
            all2Powers.push_back(i);
        }
        long long total = 0;
        for(int i:deliciousness){
            for(int j:all2Powers){
                if(dict.count(j-i)){
                    total=(total+dict[j-i])%MOD;
                }
            }
            dict[i]++;
        }

        return total;
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        in >> str;
        auto arr = getArray(str);
        vector<int> temp;
        for(auto i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                if(isPowerOf2(arr[i]+arr[j]))
                    cout<<arr[i]<<' '<<arr[j];
            }
        }
        cout << Solution().countPairs(arr);
    }
}