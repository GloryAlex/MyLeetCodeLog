#include "LeetCode.h"
using namespace std;

class Solution {
    int stoneGameVIII(vector<int>& stones) {
        auto preSum=stones;
        for(int i=1;i<preSum.size();i++)preSum[i]+=preSum[i-1];
        
        return 0;
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = getArray(str);
        cout << Solution().stoneGameVIII(arr)<<endl;
    }
}