#include "LeetCode.h"
using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& a) {
        if(a.empty())return 0;
        const int m=a.size(),n=a[0].size();

        int total = m*(1<<(n-1));
        for(int j=1;j<n;j++){
            int nonZero = 0;
            for(int k=0;k<m;k++)nonZero+=a[k][0]?1-a[k][j]:a[k][j];
            nonZero=max(nonZero,m-nonZero);

            total+=nonZero*(1<<(n-j-1));
        }
        return total;
    }
};

int main()
{
    ifstream in("input");
    while(!in.eof())
    {
        string str;in>>str;
        auto matrix = getMatrix(str);
        print(Solution().matrixScore(matrix));
    }
}