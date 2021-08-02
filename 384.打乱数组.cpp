#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */

// @lc code=start
class Solution {
    vector<int> nums;

   public:
    Solution(vector<int>& nums) {
        this->nums = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> result = nums;
        for(int i=(int)result.size()-1;i>=0;i--){
            int nextPos = rand()%(i+1);
            swap(result[i],result[nextPos]);
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string ops, str;
        in >> ops >> str;
        auto arr = getArray(str);
        auto op  = getStringArray(ops);
        Solution solution(arr);
        for (auto o : op) {
            if (o == "shuffle") {
                print(solution.shuffle());
            } else {
                print(solution.reset());
            }
        }
    }
}