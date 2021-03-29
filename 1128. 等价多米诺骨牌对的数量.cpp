#include "LeetCode.h"
using namespace std;

class Solution
{
    inline int getAxis(int i)
    {
        return i * (i - 1) / 2;
    }

public:
    struct domino
    {
        int first;
        int second;
        const bool operator==(const domino b) const
        {
            return (long long)first + second == (long long)b.first + b.second;
        }
    };
    struct eg_hash
    {
        size_t operator()(const domino &a) const
        { //利用x的hash值和y的hansh值做异或得到eg的hash值
            return hash<int>()(a.first) ^ hash<int>()(a.second);
        }
    };
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        unordered_map<domino, int, eg_hash> dict;
        for (const auto i : dominoes)
        {
            domino cur = domino{i[0], i[1]};
            if (dict.count(cur))
                dict[cur]++;
            else
                dict[{i[1], i[0]}]++;
        }
        int total = 0;
        for (auto i : dict)
        {
            total += getAxis(i.second);
        }
        return total;
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        in >> str;
        auto matrix = getMatrix(str);
        cout << Solution().numEquivDominoPairs(matrix) << endl;
    }
}