#include "LeetCode.h"
using namespace std;

class Solution
{
    bool isSimilar(string a, const string &b)
    {
        int posA = -1, posB = -1, len = a.size();
        for (int i = 0; i < len; i++)
        {
            if (a[i] != b[i])
            {
                if (posB >= 0 && posA >= 0)
                    return false;

                posB = posA;
                posA = i;
            }
        }
        if (posA >= 0 && posB >= 0)
            swap(a[posA], a[posB]);
        return a == b;
    }

public:
    class JointUnion
    {
        vector<int> father;

    public:
        JointUnion(int size) : father(vector<int>(size, -1)) {}
        int find(int i)
        {
            return father[i] < 0 ? i : father[i] = find(father[i]);
        }
        void join(int i, int j)
        {
            i = find(i), j = find(j);
            if (i == j)
                return;

            if (father[i] < father[j])
            {
                father[i] += father[j];
                father[j] = i;
            }
            else
            {
                father[j] += father[i];
                father[i] = j;
            }
        }
        bool isConnect(int i, int j)
        {
            return find(i) == find(j);
        }
        int getClusterCount(void)
        {
            int total = 0;
            for (int i : father)
            {
                total += (i < 0);
            }
            return total;
        }
    };
    int numSimilarGroups(vector<string> &strs)
    {
        JointUnion jUnion = JointUnion(strs.size());
        for (int i = 0, len = strs.size(); i < len; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                if (!jUnion.isConnect(i, j) && isSimilar(strs[i], strs[j]))
                {
                    jUnion.join(i, j);
                }
            }
        }
        return jUnion.getClusterCount();
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
        cout << Solution().numSimilarGroups(arr) << endl;
    }
}