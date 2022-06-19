#include "lib/leetcode.h"
using namespace std;

class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num==0)return 0;
        for(int i=1;i<=10;i++){
            if((num%10) == (k*i)%10){
                if(num>=k*i)return i;
            }
        }
        return -1;
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        int n, k;
        in >> n >> k;
        print(Solution().minimumNumbers(n, k));
    }
}