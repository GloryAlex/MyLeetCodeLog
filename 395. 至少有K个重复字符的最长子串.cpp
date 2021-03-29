#include "LeetCode.h"
using namespace std;

class Solution
{
private:
    vector<vector<int>> preSums;
    int limit;
    int getLongestSubString(int left, int right, const string &str)
    {
        if (right < left)
            return 0;

        char wrongChar = '\0';
        for (int i = 0; i < 26; i++)
        {
            int curCount = preSums[i][right + 1] - preSums[i][left];
            if (curCount)
            {
                if (curCount < limit)
                {
                    wrongChar = i + 'a';
                    break;
                }
            }
        }
        if (wrongChar == '\0')
            return right - left + 1;

        int position = left;
        for (position = left; position <= right; position++)
        {
            if (str[position] == wrongChar)
                break;
        }
        return max(getLongestSubString(left, position - 1, str), getLongestSubString(position + 1, right, str));
    }

public:
    int longestSubstring(string s, int k)
    {
        int length = s.size();

        //计算前缀和
        this->preSums = vector<vector<int>>(26, vector<int>(length + 1));
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                preSums[j][i + 1] = preSums[j][i];
            }
            preSums[s[i] - 'a'][i + 1]++;
        }
        this->limit = k;
        //递归地计算结果
        return getLongestSubString(0, length - 1, s);
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        int n;
        in >> str >> n;
        str = string(str.begin() + 1, str.end() - 1);
        print(Solution().longestSubstring(str, n));
    }
}