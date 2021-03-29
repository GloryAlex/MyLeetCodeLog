#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    vector<int> ans = {1,10};
    int countNumbersWithUniqueDigits(int n)
    {
        if(ans.size()>n)return ans[n];
        
        ans.push_back(getSum(n)+countNumbersWithUniqueDigits(n-1));
        return ans.back();
    }
private:
    int getSum(int n){
        if(n<2)return ans[n];
        
        int ret = 9, value = 9;
        while(--n){
            ret*=(value--);
        }
        return ret;
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        in >> str;
        auto a = stoi(str);
        print(Solution().countNumbersWithUniqueDigits(a));
    }
}