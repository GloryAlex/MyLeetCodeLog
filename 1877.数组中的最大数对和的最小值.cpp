#include "LeetCode.h"

using namespace std;
class Solution {
   public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ret = INT_MIN;
        for (int i = 0, length = nums.size(); i < length / 2; i++) {
            ret = max(ret, nums[i] + nums[length - 1 - i]);
        }
        return ret;
    }
};
int main(int argc, char* argv[]) {
    ifstream in("input");
    while (!in.ios_base::eof()) {
        string str;
        in >> str;
        auto arr = getArray(str);
        print(Solution().minPairSum(arr));
    }
}