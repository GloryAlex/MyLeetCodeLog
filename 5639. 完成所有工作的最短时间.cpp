#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    int minimumTimeRequired(vector<int> &jobs, int k)
    {
        if(k>=jobs.size())return *max_element(jobs.begin(),jobs.end());
        
        
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        int k;
        in >> str >> k;
        auto arr = getArray(str);
        cout << Solution().minimumTimeRequired(arr, k)<<endl;
    }
}