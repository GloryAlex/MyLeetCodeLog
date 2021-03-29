#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    class JointUnion
    {
    private:
        int size;

    public:
        vector<int> father;
        JointUnion(int _size) : size(_size),
                                father(vector<int>(size*size, -1)) {}
        inline int getId(int x, int y)
        {
            return x * size + y;
        }
        int find(int x, int y)
        {
            return find(getId(x, y));
        }
        int find(int id)
        {
            return father[id] < 0 ? id : father[id] = find(father[id]);
        }
        void join(int i_x, int i_y, int j_x, int j_y)
        {
            join(find(i_x, i_y), find(j_x, j_y));
        }
        void join(int a, int b)
        {
            if (a == b)
                return;
            if (father[a] < father[b])
            {
                father[a] += father[b];
                father[b] = a;
            }
            else
            {
                father[b] += father[a];
                father[a] = b;
            }
        }
        bool isConnect(int a_id, int b_id)
        {
            return find(a_id) == find(b_id);
        }
    };
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<pair<int, int>> allNodes(n * n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int curHeight = grid[i][j];
                allNodes[curHeight] = {i, j};
            }
        }

        JointUnion jUnion = JointUnion(n);
        int beginId = jUnion.getId(0, 0), endId = jUnion.getId(n - 1, n - 1);
        //TODO
        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        for (int i = 0; i < n * n; i++)
        {
            auto cur = allNodes[i];
            for (auto direction : directions)
            {
                auto next = pair<int, int>{cur.first + direction.first, cur.second + direction.second};
                if (next.first >= 0 && next.first < n && next.second >= 0 && next.second < n)
                {
                    if (grid[next.first][next.second] < i)
                    {
                        jUnion.join(cur.first, cur.second, next.first, next.second);
                    }
                }
            }

            if (jUnion.isConnect(beginId, endId))
                return i;
        }
        return n;
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
        cout << Solution().swimInWater(matrix);
    }
}