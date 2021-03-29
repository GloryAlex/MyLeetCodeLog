#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    vector<string> removeComments(vector<string> &source)
    {
        //TODO
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        in >> str;
        auto arr = getStringArray(str);
        print(Solution().removeComments(arr));
    }
}