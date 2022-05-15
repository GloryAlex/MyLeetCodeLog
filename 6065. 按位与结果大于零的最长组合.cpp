#include "lib/leetcode.h"
using namespace std;

class Solution {
   public:
    int largestCombination(vector<int>& candidates) {
        vector<int> cnt(32,0);
        for(int i:candidates){
            auto b = bitset<32>(i);
            for(int j=0;j<32;j++)cnt[j]+=b[j];
        }
        return *max_element(cnt.begin(),cnt.end());
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto c = j.get<vector<int>>();
        print(Solution().largestCombination(c));
    }
}