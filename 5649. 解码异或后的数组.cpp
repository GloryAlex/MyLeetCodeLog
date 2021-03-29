#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    vector<int> decode(vector<int> &encoded, int first)
    {
        vector<int> ret{first};
        for(auto i:encoded){
            int cur = ret.back()^i;
            ret.push_back(cur);
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
        int k;
        in >> str >> k;
        auto arr = getArray(str);
        print(Solution().decode(arr, k));
    }
}