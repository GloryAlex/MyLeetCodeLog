#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */

// @lc code=start
class Solution {
 public:
  int openLock(vector<string>& deadends, string target) {
    auto steps = 0;
    auto begin="0000";
    auto seen = unordered_set<string>(deadends.begin(), deadends.end());
    auto q = queue<string>({begin});

    auto addIfNotVisit = [&](const string& s){
        if(seen.count(s))return;
        seen.insert(s);
        q.push(s);
    };
    //判断一些特殊情况
    if(seen.count(begin)||seen.count(target))return -1;
    //开始搜索
    seen.insert(begin);
    while(!q.empty()){
        int count = q.size();
        while(count--){
            auto cur = q.front();
            q.pop();
            if(cur==target)return steps;
            for(int i=0;i<4;i++){
                //逐位操作
                cur[i]=(cur[i]=='9'?'0':cur[i]+1);
                addIfNotVisit(cur);
                cur[i]=(cur[i]-'0'+8)%10+'0';//位向左拨2
                addIfNotVisit(cur);
                cur[i]=(cur[i]=='9'?'0':cur[i]+1);;//恢复原样
            }
        }
        steps++;
    }
    return -1;
  }
};
// @lc code=end
int main() {
  ifstream in("input");
  while (!in.eof()) {
    string str, target;
    in >> str >> target;
    auto arr = getStringArray(str);
    target=getString(target);
    print(Solution().openLock(arr, target));
  }
}
