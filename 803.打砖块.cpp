#include "LeetCode.h"
using namespace std;

class JointCluster
{
    vector<int> father;

public:
    JointCluster(int length) : father(vector<int>(length, -1)) {}
    int getClusterSize(int x)
    {
        return -father[find(x)];
    }
    int find(int x)
    {
        return father[x] < 0 ? x : father[x] = find(father[x]);
    }
    bool unionCluster(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y)
            return false;

        if (father[x] < father[y])
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
class Solution
{
public:
    vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits)
    {
        const int m = grid.size(), n = grid[0].size();
        const int root = m * n;
        JointCluster jCluster = JointCluster(m * n + 1);

        for (const auto &i : hits)
        {
            grid[i[0]][i[1]]--;
        }

        const vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        //合并稳定结点
        for (int j = 0; j < n; j++)
        {
            if (grid[0][j]>0)
            {
                jCluster.unionCluster(root, j);
            }
        }
        //合并其他结点
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j]>0)
                {
                    for (const auto &k : directions)
                    {
                        int nextI = i + k.first, nextJ = j + k.second;
                        if (nextI >= 0 && nextI < m && nextJ >= 0 && nextJ < n)
                        {
                            if (grid[nextI][nextJ]>0)
                            {
                                jCluster.unionCluster(i * n + j, nextI * n + nextJ);
                            }
                        }
                    }
                }
            }
        }

        //逆序计算结果
        vector<int> ret(hits.size());
        for (int index = (int)hits.size() - 1; index >= 0; index--)
        {
            int i = hits[index][0], j = hits[index][1];
            if (++grid[i][j]>0)
            {
                int prev = jCluster.getClusterSize(root);
                if (i == 0)
                    jCluster.unionCluster(root, i * n + j);
                for (const auto &k : directions)
                {
                    int nextI = i + k.first, nextJ = j + k.second;
                    if (nextI >= 0 && nextI < m && nextJ >= 0 && nextJ < n && grid[nextI][nextJ]>0)
                    {
                        jCluster.unionCluster(i * n + j, nextI * n + nextJ);
                    }
                }
                int cur = jCluster.getClusterSize(root);
                ret[index] = max(0, cur - prev - 1);
            }
            else
                ret[index] = 0;
        }

        return ret;
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str, str2;
        in >> str >> str2;
        auto grid = getMatrix(str),
             hits = getMatrix(str2);
        auto res = Solution().hitBricks(grid, hits);
        print(res);
    }
}