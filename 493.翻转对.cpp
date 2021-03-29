#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if(nums.size())return getReversePairNums(nums.begin(),nums.end()-1);
        else return 0;
    }
    int getReversePairNums(vector<int>::iterator begin,vector<int>::iterator end){
        if(begin>=end)return 0;
        auto mid = begin + (end-begin)/2, head = begin;
        int left = getReversePairNums(begin,mid);
        int right = getReversePairNums(mid+1,end);

//统计翻转对个数
        int count = 0;
        auto l = begin,l_back = mid,r = mid+1,r_back = end;
        while(l<=l_back && r<=r_back){
            while(l<=l_back && *l <= 2LL*(*r)){
                l++;
            }
            count += (l_back-l)+1;
            r++;
        }
//归并排序
        vector<int> arr(end-begin+1);
        arr.resize(0);

        mid++;
        while(begin<=l_back && mid <= r_back){
            if(*begin<*mid)arr.push_back(*begin++);
            else arr.push_back(*mid++);
        }
        while(begin<=l_back)arr.push_back(*begin++);
        while (mid<=r_back)arr.push_back(*mid++);
        for(auto i:arr)*head++=i;

        return left+right+count;
    }
};

int main(void)
{
    string str;
    ifstream in("input");
    while(!in.eof()){
        in>>str;
        auto arr = getArray(str);
        printf("%d\n",Solution().reversePairs(arr));
    }
}