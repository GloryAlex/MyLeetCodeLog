#include "lib/leetcode.h"
using namespace std;

class Solution {
   public:
    int partitionArray(vector<int>& nums, int k) {
        set<int> s(nums.begin(),nums.end());
        nums=vector<int>(s.begin(),s.end());
        
        int cnt=0;
        for(int i=0;i<nums.size();cnt++){
            int j=i+1;
            while(j<nums.size()&&nums[j]-nums[i]<=k)j++;
            i=j;
        }
        return cnt;
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        int k;
        in >> j >> k >> ws;
        auto a = j.get<vector<int>>();
        print(Solution().partitionArray(a, k));
    }
}