#include "LeetCode.h"

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string stk;

        for(auto i:num){
            while(!stk.empty() && stk.back()<i && k){
                stk.pop_back();
                k--;
            }
            stk.push_back(i);
        }
        while(k--)stk.pop_back();

        //处理前导零
        auto realBegin = stk.begin(),end=stk.end();
        while(realBegin<end&&*realBegin=='0')realBegin++;

        return realBegin==end?"0":string(realBegin,end);
    }
};

int main()
{
    ifstream in("input");
    while(!in.eof()){
        string num;
        int k;
        in>>num>>k;

        num = num.substr(1,num.size()-2);
        cout<<Solution().removeKdigits(num,k);
    }
}
