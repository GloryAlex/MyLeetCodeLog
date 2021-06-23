#include "LeetCode.h"
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n){
            n&=(n-1);
            cnt++;
        }
        return cnt;
    }
};

int main(){
    ifstream in("input");
    while(!in.eof()){
        uint32_t n;
        in>>n;
        cout<<Solution().hammingWeight(n)<<endl;
    }
}