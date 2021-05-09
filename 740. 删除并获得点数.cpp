#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        // 构造变换数组
        map<int, int> dict;
        for (int i : nums)
            dict[i]++;

        int length = dict.rbegin()->first;
        vector<int> trans = vector<int>(length + 1);
        for (auto i : dict)
            trans[i.first] = i.second*i.first;
        // 查找结果
        if (trans.size() < 2)
            return trans[0];
        int pre2 = trans[0], pre1 = trans[1];
        for (int i = 2; i < trans.size(); i++)
        {
            int cur = max(pre1, pre2 + trans[i]);
            pre2=pre1;
            pre1=cur;
        }
        return max(pre1, pre2);
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        in >> str;
        auto arr = getArray(str);
        cout << Solution().deleteAndEarn(arr)<<endl;
    }
}