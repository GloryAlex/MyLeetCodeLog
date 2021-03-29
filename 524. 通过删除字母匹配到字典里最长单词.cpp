#include "LeetCode.h"
using namespace std;

class Solution
{
    bool IsChild(const string &father, const string &child)
    {
        int fatherIndex = 0, childIndex = 0;
        for (int fatherLength = father.length(), childLength = child.length();
             /*check need be first than compare*/;
             fatherIndex++, childIndex++)
        {
            while (fatherIndex < fatherLength && father[fatherIndex] != child[childIndex])
                fatherIndex++;

            if (fatherIndex >= fatherLength || childIndex >= childLength)
                break;
        }
        return childIndex == child.length();
    }

public:
    string findLongestWord(string s, vector<string> &dictionary)
    {
        sort(dictionary.begin(), dictionary.end(), [&](const string &a, const string &b) {
            return a.length() == b.length() ? a < b : a.length() > b.length();
        });

        for (const auto &word : dictionary)
        {
            if (IsChild(s, word))
                return word;
        }
        return "";
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str1, str2;
        in >> str1 >> str2;
        string s = getString(str1);
        auto dict = getStringArray(str2);
        print(Solution().findLongestWord(s, dict));
    }
}