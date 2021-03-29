#include "LeetCode.h"
using namespace std;

class Solution {
private:
    int ugly[1690];
public:
    Solution(){
        ugly[0]=1;
        int i2=0,i3=0,i5=0;
        for(int i=1;i<1690;i++){
            int cur = min(min(ugly[i2]*2,ugly[i3]*3),ugly[i5]*5);
            ugly[i]=cur;
            
            if(cur==ugly[i2]*2)i2++;
            if(cur==ugly[i3]*3)i3++;
            if(cur==ugly[i5]*5)i5++;
        }
    }
    int nthUglyNumber(int n) {
        return ugly[n-1];
    }
};

int main()
{
    ifstream in("input");
    while(!in.eof()){
        int n;
        in>>n;
        print(Solution().nthUglyNumber(n));
    }
}