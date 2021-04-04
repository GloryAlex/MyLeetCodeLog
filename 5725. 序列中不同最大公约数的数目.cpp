#include "LeetCode.h"
using namespace std;

class Solution
{
    const int MOD=1e9+7;
    const int MAX_SIZE=2e5+1;
    vector<int> isInNums=vector<int>(MAX_SIZE);
    int maxOfNums;
    inline int gcd(int a,int b) {
        while(b^=a^=b^=a%=b);
        return a;
    }
    bool isOneOfGCDs(int x){
        int curGcd = -1;
        for(int i=x;i<=maxOfNums;i+=x){
            if(isInNums[i]){
                if(curGcd==-1)curGcd=i;
                else curGcd=gcd(curGcd,i);

                if(curGcd==x)return true;
            }
        }
        return curGcd==x;
    }
public:
    int countDifferentSubsequenceGCDs(vector<int> &nums)
    {
        //init neccessary values
        maxOfNums = -1;
        for(int i:nums){
            isInNums[i]=true;
            maxOfNums=max(maxOfNums,i);
        }
        //check all elements in range
        long long total=0;
        for(int i=1;i<=maxOfNums;i++){
            total+=isOneOfGCDs(i);
        }
        return total%MOD;
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
        cout << Solution().countDifferentSubsequenceGCDs(arr)<<endl;
    }
}