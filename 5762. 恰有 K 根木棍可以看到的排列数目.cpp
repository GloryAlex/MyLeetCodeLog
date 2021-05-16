#include "LeetCode.h"
using namespace std;
class Solution {
   private:
    vector<vector<long long>> dp;
    const int MOD = 1e9 + 7;
    long long getRearangeSticks(long long i, long long n, int remain) {
        if (dp[i][remain] != -1) return dp[i][remain];

        return dp[i][remain] =
                   (((n - i) * getRearangeSticks(i + 1, n, remain - 1)%MOD) +
                   getRearangeSticks(i + 1, n, remain)%MOD);
    }

   public:
    int rearrangeSticks(int n, int k) {
        dp = vector<vector<long long>>(n + 1, vector<long long>(n - k + 1, -1));
        for(int i=0;i<=n;i++)dp[i][0]=1;
        for(int i=1;i<=n-k;i++)dp[n][i]=0;

        return getRearangeSticks(1, n, n - k) % MOD;
    }
};
int main() {
    ifstream in("input");
    while (!in.eof()) {
        int a, b;
        in >> a >> b;
        cout << Solution().rearrangeSticks(a, b) << endl;
    }
}