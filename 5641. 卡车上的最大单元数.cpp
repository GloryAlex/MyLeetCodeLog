#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        sort(boxTypes.begin(),boxTypes.end(),[&](vector<int>& a,vector<int>&b){
            return a[1]>b[1];
        });
        int sum = 0;
        for(auto &i:boxTypes){
            int num = min(truckSize,i[0]);
            sum+=num*i[1];
            truckSize-=num;
            if(truckSize==0)break;
        }
        return sum;
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        in >> str;
        auto arr = getMatrix(str);
        int n;
        in >> n;
        cout << Solution().maximumUnits(arr, n);
    }
}