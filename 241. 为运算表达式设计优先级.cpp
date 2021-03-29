#include "LeetCode.h"
using namespace std;

class Solution
{
    unordered_map<string, vector<int>> dict;
    unordered_set<char> operators = {'+', '-', '*'};

public:
    vector<int> diffWaysToCompute(string input)
    {
        if (dict.count(input))
            return dict[input];

        vector<int> ret;
        if (isAllDigit(input))
            ret = {stoi(input)};
        else
        {
            for (auto i = input.begin(); i != input.end(); i++)
            {
                if (operators.count(*i))
                {
                    auto leftResults = diffWaysToCompute(string(input.begin(), i));
                    auto rightResults = diffWaysToCompute(string(i + 1, input.end()));

                    for (auto l : leftResults)
                    {
                        for (auto r : rightResults)
                        {
                            switch (*i)
                            {
                            case '+':
                                ret.emplace_back(l + r);
                                break;
                            case '-':
                                ret.emplace_back(l - r);
                                break;
                            case '*':
                                ret.emplace_back(l * r);
                                break;
                            default:
                                break;
                            }
                        }
                    }
                }
            }
        }
        return dict[input] = ret;
    }

private:
    bool isAllDigit(const string &s)
    {
        for (char i : s)
            if (!isdigit(i))
                return false;
        return true;
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        in >> str;
        str = str.substr(1, str.size() - 2);
        print(Solution().diffWaysToCompute(str));
    }
}