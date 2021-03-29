#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int index = 0, i = 0, j = 0, count = 0;
        for (int i = 0; i < chars.size(); i = j)
        {
            count = 1, j = i + 1;
            while (j<chars.size() && chars[j] == chars[i])
            {
                count++;
                j++;
            }
            if (count == 1)
            {
                continue;
            }
            string sCount = to_string(count);

            chars[index++] = chars[i];
            for (int k = 0; k < sCount.size(); index++, k++)
            {
                chars[index] = sCount[k];
            }
            i = j;
        }
        return index;
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
        vector<char> chars;
        for(auto i:arr)chars.push_back(i[0]);
        cout<<Solution().compress(chars)<<endl;
        print(chars);
    }
}