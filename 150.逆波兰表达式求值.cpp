#include "LeetCode.h"
#include <regex>
using namespace std;

class Solution
{
    int caculate(int first, int second, char op)
    {
        if (op == '+')
            return first + second;
        if (op == '-')
            return first - second;
        if (op == '*')
            return first * second;
        if (op == '/')
            return first / second;
        return 0;
    }

public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> nums;
        regex operatorPattern = regex("[+-/*]");
        for (auto token : tokens)
        {
            if (regex_match(token,operatorPattern))
            {
                int second = nums.top();
                nums.pop();
                int first = nums.top();
                nums.pop();
                nums.push(caculate(first, second, token[0]));
            }
            else
            {
                nums.push(stoi(token));
            }
        }
        return nums.top();
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
        cout << Solution().evalRPN(arr);
    }
}