#include "lib/leetcode.h"
using namespace std;

class Solution {
    struct vec_hash {
        std::size_t operator()(std::vector<int> const& vec) const {
            std::size_t seed = vec.size();
            for (auto& i : vec) {
                seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            return seed;
        }
    };
    int cnt = 0;
    vector<int> temp;
    unordered_set<vector<int>, vec_hash> s;
    void dfs(int index, vector<int>& nums, int remain, int p) {
        //每个位置都可以选择加入或不加入
        //选择不加入
        if(!s.count(temp)){
            s.insert(temp);
            cnt++;
        }
        //选择加入
        if (index >= nums.size())return;
        if (nums[index] % p == 0) remain--;
        if (remain >= 0) {
            temp.push_back(nums[index]);
            dfs(index + 1, nums, remain, p);
        }
    }

   public:
    int countDistinct(vector<int>& nums, int k, int p) {
        for(int i=0;i<nums.size();i++){
            temp.clear();
            dfs(i, nums, k, p);
        }
        return cnt-1;
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        int k, p;
        json j;
        in >> j >> ws;
        in >> k >> p >> ws;
        auto a = j.get<vector<int>>();
        cout << Solution().countDistinct(a, k, p) << endl;
    }
}