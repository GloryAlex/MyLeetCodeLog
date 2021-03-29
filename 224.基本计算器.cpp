#include "LeetCode.h"
using namespace std;

class Solution
{
    private:
    int getNextInteger(const string& s,int& pos){
        int begin=pos;
        while(pos!=s.size()&&isdigit(s[pos]))pos++;

        return stoi(s.substr(begin,pos-begin));
    }
    inline int operation(int a,int b,char operation){
        if(operation=='+')return a+b;
        else return a-b;
    }
    int getExpression(const string& s,int& pos){
        int cur = 0;
        char _operator = '+';
        while(pos<s.size()){
            switch(s[pos]){
                case ' ':pos++;continue;
                case ')':pos++;return cur;
                case '(':pos++;cur = operation(cur,getExpression(s,pos),_operator);
                case '+':
                case '-':_operator = s[pos++];break;
                default: cur = operation(cur,getNextInteger(s,pos),_operator);
            }
        }
        return cur;
    }
public:
    int calculate(string s)
    {
        int pos = 0;
        return getExpression(s,pos);
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
        print(Solution().calculate(str));
    }
}