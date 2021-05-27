#include "LeetCode.h"
using namespace std;

class Solution {
   public:
    int minCost(vector<vector<int>>& costs) {
        int houseCount = costs.size();
        auto dp = costs;
        
        for(int i=1;i<houseCount;i++){
            dp[i][0]+=min(dp[i-1][1],dp[i-1][2]);
            dp[i][1]+=min(dp[i-1][0],dp[i-1][2]);
            dp[i][2]+=min(dp[i-1][1],dp[i-1][0]);
        }
        return min(dp.back().at(0),min(dp.back().at(1),dp.back().at(2)));
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = getMatrix(str);
        cout << Solution().minCost(arr) << endl;
    }
}