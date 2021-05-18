#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=1442 lang=cpp
 *
 * [1442] 形成两个异或相等数组的三元组数目
 */

// @lc code=start
class Solution {
   public:
    int countTriplets(vector<int>& arr) {
        //前缀和数组，arr[i]-arr[j]的异和前缀和等于presum[j+1]^presum[i]
        auto preSum = vector<int>(arr.size()+1);
        for(int i=0;i<arr.size();i++){
            preSum[i+1]=preSum[i]^arr[i];
        }
        //两重循环求解
        int total = 0;
        for(int i=0;i<arr.size();i++){
            for(int k=i+1;k<arr.size();k++){
                if(preSum[i]==preSum[k+1])total+=k-i;
            }
        }
        return total;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = getArray(str);
        cout << Solution().countTriplets(arr) << endl;
    }
}