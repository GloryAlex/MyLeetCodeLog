#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n+1,true);
        vector<int> primes;

        for(int i=2;i<n;i++){
            if(isPrime[i]){
                primes.push_back(i);
            }
            for(auto j:primes){
                isPrime[i*j]=false;
                if(!(i%j))break;
            }
        }
        return primes.size();
    }
};

int main()
{
    ifstream in("input");
    while(!in.eof())
    {
        int n;
        in>>n;
        print(Solution().countPrimes(n));
    }
}