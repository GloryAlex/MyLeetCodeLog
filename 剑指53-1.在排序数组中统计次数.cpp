#include "LeetCode.h"

using namespace std;

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = (int)nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        }
        int total = 0;
        for (int i = left; i < nums.size(); i++) {
            if (nums[i] != target)
                break;
            else
                total++;
        }
        return total;
    }
};

int main(int argc, char* argv[]) {
    auto in = ifstream("input");
    while (!in.eof()) {
        string str;
        int target;
        in >> str >> target;
        auto arr = getArray(str);
        print(Solution().search(arr, target));
    }
}