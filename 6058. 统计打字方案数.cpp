#include "lib/leetcode.h"
using namespace std;

class Solution {
    const int MOD = 1e9 + 7;
    unordered_map<int, long long> threeCount = {{0, 1}, {1, 1}};
    unordered_map<int, long long> fourCount = {{0, 1}, {1, 1}};
    long long getThreeCount(int val) {
        if(threeCount.count(val))return threeCount[val];
        long long total=0;
        for(int i=1;i<=3;i++){
            if(val-i<0)break;
            long long temp=getThreeCount(val-i);
            total=(total+temp)%MOD;
        }
        return threeCount[val]=total;
    }
    long long getFourCount(int val) {
        if(fourCount.count(val))return fourCount[val];
        long long total=0;
        for(int i=1;i<=4;i++){
            if(val-i<0)break;
            long long temp=getFourCount(val-i);
            total=(total+temp)%MOD;
        }
        return fourCount[val]=total;
    }

   public:
    int countTexts(string keys) {
        vector<pair<int, int>> arr;
        for (int i = 0, j = 0; i < keys.size(); i = j) {
            j = i + 1;
            while (j < keys.size() && keys[j] == keys[i]) j++;
            arr.emplace_back(pair<int, int>{keys[i] - '0', j - i});
        }

        long long res=1;
        for(auto [val,cnt]:arr){
            if(val==7||val==9)res=(res*getFourCount(cnt))%MOD;
            else res=(res*getThreeCount(cnt))%MOD;
        }
        return res;
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto s = j.get<string>();
        print(Solution().countTexts(s));
    }
}