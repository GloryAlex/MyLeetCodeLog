#include <random>

#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        array<int, 32> bitSums = {0};
        for (int num : nums) {
            for (int i = 0; i < 32; i++) {
                bitSums[i] += (num >> i) & 1;
            }
        }

        int ans = 0;
        for (int i = 0; i < 32; i++) {
            if (bitSums[i] % 3) ans |= (1 << i);
        }
        return ans;
    }
};
// @lc code=end

bool tester(int times) {
    default_random_engine e(time(NULL));
    uniform_int_distribution<int> randomInt(0,(int)3e4);

    for (int i = 0; i < times; i++) {
        printf("开始进行测试: %d\n",i);
        int size = randomInt(e);
        vector<int> testArray;
        while (testArray.size() < size) {
            int cur = randomInt(e);
            for (int j = 0; j < 3; j++) testArray.push_back(cur);
        }
        int ans = randomInt(e);
        testArray.push_back(ans);
        shuffle(testArray.begin(), testArray.end(), mt19937());

        int testAns = Solution().singleNumber(testArray);

        if(testAns == ans){
            printf("测试 %d 通过\n",i);
        }else{
            printf("测试 %d 未通过\n测试数据:\n",i);
            print(testArray);
            printf("正确答案:%d\n你的答案:%d\n",ans,testAns);
            printf("测试结束\n");
            return false;
        }
    }
    return true;
}

int main() {
    tester(100);
}