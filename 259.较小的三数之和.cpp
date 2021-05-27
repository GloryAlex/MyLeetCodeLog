#include "LeetCode.h"
using namespace std;

class Solution {
   public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int ret = 0;
        sort(nums.begin(),nums.end());
        for (int i = 0; i < nums.size(); i++)
            ret += countTwoSmaller(nums, i + 1, target - nums[i]);
        return ret;
    }
    int countTwoSmaller(vector<int>& nums, int begin, int target) {
        int left = begin, right = (int)nums.size() - 1;
        int total = 0;
        while (left < right) {
            if (nums[left] + nums[right] < target) {
                total += right - left;
                left++;
            } else
                right--;
        }
        return total;
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = getArray(str);
        int target;
        in >> target;
        cout << Solution().threeSumSmaller(arr, target) << endl;
    }
}