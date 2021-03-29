#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    class JointCluster
    {
    private:
        unordered_map<int, int> father;

    public:
        int getCount()
        {
            int count = 0;
            for (auto i : father)
            {
                count += (i.second < 0);
            }
            return count;
        }
        int find(int x)
        {
            if(!father.count(x))father[x]=-1;
            int fx = father[x];
            return fx < 0 ? x : father[x] = find(fx);
        }
        bool unionCluster(int x, int y)
        {
            x = find(x), y = find(y);
            int fx = father[x], fy = father[y];

            if (x == y)
                return false;

            if (fx < fy)
            {
                father[x] += father[y];
                father[y] = x;
            }
            else
            {
                father[y] += father[x];
                father[x] = y;
            }
            return true;
        }
    };

    int removeStones(vector<vector<int>> &stones)
    {
        JointCluster f;
        for(const auto& i:stones){
            f.unionCluster(i[0]+10001,i[1]);
        }

        return stones.size()-f.getCount();
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        in >> str;
        auto arr = getMatrix(str);
        cout << Solution().removeStones(arr) << endl;
    }
}