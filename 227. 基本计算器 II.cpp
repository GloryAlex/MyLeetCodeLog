#include "LeetCode.h"
using namespace std;

class Solution
{
private:
    int getNextInteger(const string &s, int &pos)
    {
        int begin = pos;
        while (pos != s.size() && isdigit(s[pos]))
        {
            pos++;
        }
        return stoi(s.substr(begin, pos - begin));
    }
public:
    int calculate(string s)
    {
        //移除所有空格
        int size=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' ')s[size++]=s[i];
        }
        s.resize(size);
        if (s.empty())
            return 0;
        //开始计算
        vector<int> numbers;
        vector<char> operations;
        int pos = 0;
        while (pos != s.size())
        {
            if (s[pos] == '+' || s[pos] == '-')
            {
                operations.push_back(s[pos++]);
            }
            else if (s[pos] == '*' || s[pos] == '/')
            {
                char curOperator = s[pos++];
                int num = getNextInteger(s, pos);

                numbers.back() = curOperator == '*' ? numbers.back() * num : numbers.back() / num;
            }
            else
            {
                numbers.push_back(getNextInteger(s, pos));
            }
        }
        int cur = numbers[0];
        for (int i = 0; i < operations.size(); i++)
        {
            if (operations[i] == '+')
                cur += numbers[i + 1];
            else
                cur -= numbers[i + 1];
        }
        return cur;
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        getline(in, str);
        if (str.size() && str[0] == '"')
            str = string(str.begin() + 1, str.end() - 1);
        cout << Solution().calculate(str) << endl;
    }
}