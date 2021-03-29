#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    int numDifferentIntegers(string word)
    {
        unordered_set<string> dict;
        for (int i = 0, len = word.size(); i < len;)
        {
            if (isdigit(word[i]))
            {
                int begin = i;
                while (i < len && isdigit(word[i]))
                    i++;
                while(begin<i&&word[begin]=='0')begin++;
                dict.insert(word.substr(begin,i-begin));
            }
            else
                i++;
        }
        return dict.size();
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        in >> str;
        auto arr = getString(str);
        cout << Solution().numDifferentIntegers(arr);
    }
}