#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=798 lang=cpp
 *
 * [798] 得分最高的最小轮调
 */

// @lc code=start
class Solution {
    struct DiffArray {
        private:
        vector<int> arr;
        public:
        DiffArray(int size) : arr(vector<int>(size)) {}
        void add(int l, int r) {
            arr[l]++;
            arr[r]--;
            if(l>=r)arr[0]++;
        }
        vector<int> restore(){
            vector<int> res;
            int score=0;
            for(int i:arr){
                score+=i;
                res.push_back(score);
            }
            return res;
        }
    };

   public:
    int bestRotation(vector<int>& nums) {
        int n=nums.size();
        DiffArray diff = DiffArray(nums.size());
        for(int i=0;i<n;i++){
            int low = (i+1)%n;
            int high=(i-nums[i]+1+n)%n;
            diff.add(low,high);
        }
        auto scores = diff.restore();
        return max_element(scores.begin(),scores.end())-scores.begin();
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto arr = j.get<vector<int>>();
        cout << Solution().bestRotation(arr) << endl;
    }
}