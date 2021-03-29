#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    void wallsAndGates(vector<vector<int>> &rooms)
    {
        typedef pair<int, int> point;
        const int m = rooms.size(), n = rooms[0].size();
        const vector<point> direction = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        queue<point> q;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (rooms[i][j] == 0)
                    q.push({i, j});

        while (!q.empty())
        {
            auto curPoint = q.front();
            q.pop();
            for (const auto &i : direction)
            {
                int x = curPoint.first + i.first;
                int y = curPoint.second + i.second;
                if (x >= 0 && x < m && y >= 0 && y < n && rooms[x][y] != -1)
                {
                    if (rooms[x][y] > rooms[curPoint.first][curPoint.second] + 1)
                    {
                        rooms[x][y] = rooms[curPoint.first][curPoint.second] + 1;
                        q.push({x, y});
                    }
                }
            }
        }
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
        Solution().wallsAndGates(arr);
        print(arr);
    }
}