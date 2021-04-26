#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    bool findWhetherExistsPath(int n, vector<vector<int>> &input, int start, int target)
    {
        vector<vector<int>> graph = vector<vector<int>>(n);
        //建图
        for(const auto& edge:input){
            graph[edge[0]].emplace_back(edge[1]);
            //如果是无向图取消注释
            // graph[edge[1]].emplace_back(edge[0]);
        }
        vector<int> hasVisit = vector<int>(n,false);
        //bfs
        queue<int> q = queue<int>({start});
        while(!q.empty()){
            int curNode = q.front();
            if(curNode==target)return true;
            
            q.pop();
            for(int next:graph[curNode]){
                if(!hasVisit[next]){
                    q.push(next);
                    hasVisit[next]=true;
                }
            }
        }
        //dfs
        // stack<int> s = stack<int>({start});
        // while(!s.empty()){
        //     int curNode = s.top();
        //     if(curNode==target)return true;
            
        //     s.pop();
        //     for(int next:graph[curNode]){
        //         if(!hasVisit[next]){
        //             s.push(next);
        //             hasVisit[next]=true;
        //         }
        //     }
        // }
        return false;
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        int n, start, end;
        string str;
        in >> n >> str >> start >> end;
        auto graph = getMatrix(str);
        print(Solution().findWhetherExistsPath(n,graph,start,end));
    }
}