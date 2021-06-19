#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=1239 lang=cpp
 *
 * [1239] 串联字符串的最大长度
 */

// @lc code=start
class Solution {
    //maskOf 预处理只包含小写字母的字符串
    //如果字符串不包含重复字符，则转换为掩码形式；否则返回0
    //返回示例：
    //maskOf("a")=>1; maskOf("bc")=>110; maskOf("aabc")=>0
    int maskOf(const string& str) {
        int bitForm = 0;
        for (auto ch : str) {
            int mask = 1 << (ch - 'a');
            if ((bitForm & mask) != 0) return 0;
            bitForm |= mask;
        }
        return bitForm;
    }

   public:
    int maxLength(vector<string>& arr) {
        vector<int> masks;
        vector<int> lengthes;
        //预处理所有字符串，去除本身已经重复的字符串，并将其他字符串转为二进制位表示
        for (const auto& i : arr) {
            int bitForm = maskOf(i);
            if (bitForm) {
                masks.push_back(bitForm);
                lengthes.push_back(i.length());
            }
        }
        auto dict = vector<unordered_map<int, int>>(masks.size());//存储已查找过的最大长度，加速查找
        //记忆化搜索答案
        return findMaxLength(0, 0, masks, lengthes, dict);
    }
    //findMaxLength
    int findMaxLength(int index, int curWords, vector<int>& masks, vector<int>& lengthes,
            vector<unordered_map<int, int>>& dict) {
        if (index >= masks.size()) return 0;
        if (dict[index].count(curWords)) return dict[index][curWords];
        int maxLength = 0;
        for (int i = index; i < masks.size(); i++) {
            if (!(curWords & masks[i])) {  //当前字符集和masks[i]字符集不冲突
                maxLength = max(
                    maxLength, lengthes[i] + findMaxLength(index + 1, curWords | masks[i],
                                                 masks, lengthes, dict));
            }
        }
        return dict[index][curWords] = maxLength;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = getStringArray(str);
        print(Solution().maxLength(arr));
    }
}