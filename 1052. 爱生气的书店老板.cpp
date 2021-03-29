#include "LeetCode.h"
#include <numeric>
using namespace std;

class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int x)
    {
        int length = customers.size();

        vector<int> extra = vector<int>(length);

        int origin = 0;
        for (int i = 0; i < length; i++)
        {
            origin += customers[i] * !grumpy[i];
            extra[i]=customers[i] * grumpy[i];
        }
        //求得extra所有长度为x的连续子数组中的最大值
        int maxChildSum = accumulate(extra.begin(),extra.begin()+x,0);
        for(int i=x,curChildSum=maxChildSum;i<length;i++){
            curChildSum+=extra[i]-extra[i-x];
            maxChildSum=max(maxChildSum,curChildSum);
        }
        return origin+maxChildSum;
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        in >> str;
        auto arr = getArray(str);
        in >> str;
        auto arr2 = getArray(str);
        int k;
        in >> k;
        print(Solution().maxSatisfied(arr, arr2, k));
    }
}