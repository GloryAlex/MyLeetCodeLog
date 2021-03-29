#include "LeetCode.h"
using namespace std;

class Solution
{
    inline int getANN(int i){
        return i*(i-1);
    }
public:
    int tupleSameProduct(vector<int> &nums)
    {
        unordered_map<int, int> dict;
        for (auto i = nums.begin(), end = nums.end(); i != end; i++)
        {
            for (auto j = i + 1; j != end; j++)
            {
                if (*i == *j)
                    continue;
                dict[*i * *j]++;
            }
        }
        int total = 0;
        for(const auto &i:dict){
            if(i.second>1)total+=getANN(i.second);
        }
        return 4*total;
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
        cout << Solution().tupleSameProduct(arr)<<endl;
    }
}