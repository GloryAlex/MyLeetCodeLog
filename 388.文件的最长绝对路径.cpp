#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=388 lang=cpp
 *
 * [388] 文件的最长绝对路径
 */

// @lc code=start
class Solution {
   public:
    int lengthLongestPath(string input) {
        auto curPathLength = vector<int>{0};//需要存一下根深度的长度
        auto maxLength = 0, depth = 0, curLength = 0;
        auto inputStream = istringstream(input);
        auto level = string();//保存当前层文件名或文件夹名
        while(getline(inputStream,level)) {
            //计算当前深度
            auto curDepth = 0;
            for (; curDepth < level.size(); curDepth++) {
                if (level[curDepth] != '\t') break;
            }
            //返回到当前深度的上一层
            while (curDepth <= depth) {
                curLength -= curPathLength.back();
                curPathLength.pop_back();
                depth--;
            }
            //压入当前文件（夹）
            curPathLength.push_back(level.size() - curDepth);
            curLength += curPathLength.back();
            depth++;
            //如果是文件则尝试更新长度
            if (level.find('.') != level.npos) {
                maxLength = max(maxLength, curLength + depth);
            }
        }
        return maxLength;
    }
};  
// @lc code=end
int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        string inputString;
        for (int i = 1; i < str.size() - 1; i++) {
            char cur = str[i];
            if (cur == '\\') {
                i++;
                if (str[i] == 'n')
                    cur = '\n';
                else if (str[i] == 't')
                    cur = '\t';
            }
            inputString.push_back(cur);
        }
        print(Solution().lengthLongestPath(inputString));
    }
}
