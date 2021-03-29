#include "LeetCode.h"
using namespace std;

class Solution
{
    struct point
    {
        int nextId;
        int distance;

    public:
        bool operator<(const point &a)const
        {
            return distance > a.distance;
        }
    };
    const int MOD = (int)(1e9 + 7);
    int nodeNums;
    vector<int> weights;
    vector<vector<point>> graph;
    /**
     * 求最短路径算法
     * 
     */
    void Dijistra(void)
    {
        priority_queue<point, vector<point>> q;
        weights[nodeNums-1]=0;
        q.push({nodeNums-1,0});
        
        vector<int> hasVisit = vector<int>(nodeNums);
        for(int _=0;_<nodeNums;_++){
            auto cur = q.top();q.pop();
            int id = cur.nextId;

            hasVisit[id]=true;
            for(auto &next:graph[id]){
                if(!hasVisit[next.nextId] && next.distance+weights[id]<weights[next.nextId]){
                    weights[next.nextId]=next.distance+weights[id];
                    q.push({next.nextId,weights[next.nextId]});
                }
            }
        }
    }
    /**
     * DFS+记忆化搜索
     */ 
    vector<long long> dict;
    long long dfs(int i){
        if(dict[i]!=-1)return dict[i];

        long long total = 0;
        for(const auto& next:graph[i]){
            if(weights[next.nextId]<weights[i]){
                total = (total+dfs(next.nextId))%MOD;
            }
        }
        return dict[i]=total;
    }
public:
    int countRestrictedPaths(int n, vector<vector<int>> &edges)
    {
        nodeNums = n;
        //构造图
        graph = vector<vector<point>>(n);
        for (const auto &edge : edges)
        {
            int source = edge[0]-1, destination = edge[1]-1, distance = edge[2];
            graph[source].push_back({destination, distance});
            graph[destination].push_back({source, distance});
        }
        //求出每个点的最短距离
        weights = vector<int>(n,INT_MAX);
        weights[n-1]=0;
        Dijistra();
        //查找满足1-n且编号递增距离递减的所有路径的数量
        dict = vector<long long>(n,-1);
        dict[n-1]=1;

        return dfs(0);
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        int n;
        in >> n;
        string str;
        in >> str;
        auto arr = getMatrix(str);
        cout << Solution().countRestrictedPaths(n, arr) << endl;
    }
}