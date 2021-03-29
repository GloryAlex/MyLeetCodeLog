#include "LeetCode.h"
using namespace std;

class Solution
{
private:
    unordered_set<char> dict = {'a','e','i','o','u','A','E','I','O','U'};
public:
    bool halvesAreAlike(string s)
    {
        int firstCount = 0;
        int half = s.size()/2;
        for(int i=0;i<half;i++){
            if(dict.count(s[i]))firstCount++;
        }
        int secondCount = 0;
        for(int i=half;i<s.size();i++){
            if(dict.count(s[i]))secondCount++;
        }

        return firstCount==secondCount;
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
        cout << Solution().halvesAreAlike(str);
    }
}