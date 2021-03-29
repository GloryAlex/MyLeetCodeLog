#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        if(nums.size()<3)return false;
        
        unordered_map<int,int> remain,asTailNums;
        for(auto i:nums)remain[i]++;

        for(auto i:nums){
            if(remain[i]){
                if(asTailNums[i-1]){
                    //可以接在某个序列后面
                    asTailNums[i-1]--;
                    asTailNums[i]++;
                    remain[i]--;
                }else{
                    if(remain[i+1]&&remain[i+2]){//尝试新建序列
                        remain[i+1]--;
                        remain[i+2]--;
                        remain[i]--;

                        asTailNums[i+2]++;
                    }else{
                    //否则，无法分割
                    return false;
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    ifstream in("input");
    while(!in.eof()){
        string str;
        in>>str;
        auto arr = getArray(str);
        print(Solution().isPossible(arr));
    }
}