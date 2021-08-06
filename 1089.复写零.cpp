#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=1089 lang=cpp
 *
 * [1089] 复写零
 */

// @lc code=start
class Solution {
   public:
    void duplicateZeros(vector<int>& arr) {
        int count = 0;
		int len = arr.size();
		int i = 0;
		while(i + count < len) {
			if(arr[i++] == 0) count++;
		}
		i--;
		int j = len - 1;
		if(count + i + 1 > len) {
			arr[j--] = arr[i--];
			count--;
		}
		while(count > 0) {
			arr[j--] = arr[i];
			if(arr[i] == 0) {
				arr[j--] = arr[i];
				count--;
			}
			i--;
		}
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = getArray(str);
        Solution().duplicateZeros(arr);
        print(arr);
    }
}