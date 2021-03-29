#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        k=min(k,(int)prices.size()/2);
        if(k==0)return 0;

        vector<int> sell(k+1,INT_MIN/2),hold(k+1,INT_MIN/2);
        hold[0]=INT_MIN;
        sell[0]=0;

        for(int price:prices){
            hold[0]=max(hold[0],sell[0]-price);
            for(int i=1;i<=k;i++){
                sell[i]=max(sell[i],hold[i]+price);
                hold[i]=max(hold[i],sell[i-1]-price);
            }
        }

        return *max_element(sell.begin(),sell.end());
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        int k;
        string str;
        in >> k >> str;
        auto arr = getArray(str);
        print(Solution().maxProfit(k, arr));
    }
}