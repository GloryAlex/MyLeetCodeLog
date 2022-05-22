#include "lib/leetcode.h"
using namespace std;

class Solution {
   public:
    int totalStrength(vector<int>& strength) {
        int n = strength.size();
        auto presum = vector<int>(n);
        for (int i = 0; i < n; i++)
            presum[i] = strength[i] + (i == 0 ? 0 : presum[i - 1]);
        auto getSum = [&](int l, int r) {
            return presum[r] - (l == 0 ? 0 : presum[l - 1]);
        };

        long total=0;
        long mod=1e9+7;
        for(int i=0;i<n;i++){
            int minVal=INT_MAX;
            for(int j=i;j<n;j++){
                minVal=min(minVal,strength[j]);
                long sum=getSum(i,j);
                total=(total+(sum*minVal))%mod; 
            }
        }
        return total;
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto arr = j.get<vector<int>>();
        print(Solution().totalStrength(arr));
    }
}