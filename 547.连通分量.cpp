#include "LeetCode.h"
#include <assert.h>
#include <functional>
using namespace std;

class Solution
{
    int findCircleNumsByUnion(vector<vector<int>> &graph)
    {
        const int cityNums = graph.size();
        vector<int> father(cityNums, -1);

        function<int(int)> find = [&](int x) {
            return father[x] < 0 ? x : father[x] = find(father[x]);
        };
        auto unionCluster = [&](int x, int y) {
            int fx = find(x), fy = find(y);
            if (fx == fy)
                return;

            if (father[fx] > father[fy])
            {
                father[fy] += father[fx];
                father[fx] = fy;
            }
            else
            {
                father[fx] += father[fy];
                father[fy] = fx;
            }
        };

        for (int i = 0; i < cityNums; i++)
        {
            for (int j = 0; j < cityNums; j++)
            {
                if (graph[i][j])
                {
                    unionCluster(i, j);
                }
            }
        }

        int total = 0;
        for (int i : father)
        {
            if (i < 0)
                total++;
        }
        return total;
    }
    int findCircleNumsByBfs(vector<vector<int>> &graph)
    {
        const int cityNums = graph.size();

        int totalConnected = 0;
        unordered_set<int> notVisit;
        for (int i = 0; i < cityNums; i++)
        {
            notVisit.insert(i);
        }

        queue<int> q;
        while (notVisit.size())
        {
            q.push(*notVisit.begin());
            totalConnected++;

            while (!q.empty())
            {
                int cur = q.front();
                q.pop();
                if (notVisit.count(cur))
                {
                    notVisit.erase(cur);
                    for (int i = 0; i < cityNums; i++)
                    {
                        if (graph[cur][i])
                            q.push(i);
                    }
                }
            }
        }
        return totalConnected;
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int one = findCircleNumsByBfs(isConnected);
        int two = findCircleNumsByUnion(isConnected);

        assert(one == two);
        return two;
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
        cout << Solution().findCircleNum(arr) << endl;
    }
}