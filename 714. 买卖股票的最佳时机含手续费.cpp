#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        //  定义初始值
        int nowHold = INT_MIN, nowSold = 0;
        for (int price : prices)
        {
            //状态转移
            nowHold = max(nowHold, nowSold - price);
            nowSold = max(nowSold, nowHold + price - fee);
        }
        return nowSold;
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        int fee;
        in >> str >> fee;
        auto arr = getArray(str);
        print(Solution().maxProfit(arr, fee));
    }
}