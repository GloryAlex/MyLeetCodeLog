#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    string removeDuplicates(string s)
    {
        string stk;
        while (s.size())
        {
            stk.push_back(s.back());
            s.pop_back();
            while (s.size() && stk.size() && s.back() == stk.back())
            {
                s.pop_back();
                stk.pop_back();
            }
        }
        return string(stk.rbegin(),stk.rend());
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        in >> str;
        if (str.size() && str[0] == '"')
            str = string(str.begin() + 1, str.end() - 1);
        print(Solution().removeDuplicates(str));
    }
}