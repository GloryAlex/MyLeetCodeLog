#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int getMaxLen(vector<vector<int>> graph)
{
    int n = graph.size();
    //找到最远节点
    int i = 0;
    queue<int> q;
    vector<int> visited = vector<int>(n);
    q.push(i);
    while (!q.empty())
    {
        i = q.front();
        q.pop();
        visited[i] = true;
        for (int j : graph[i])
            if (!visited[j])
                q.push(j);
    }
    //基于最远节点找最远节点
    visited = vector<int>(n);
    q.push(i);
    int cnt = 0;
    while (!q.empty())
    {
        int count = q.size();
        while (count--)
        {
            i = q.front();
            q.pop();
            visited[i] = true;
            for (int j : graph[i])
                if (!visited[j])
                    q.push(j);
        }
        cnt++;
    }
    //求路径
    return cnt-1;
}

int divide(int x){
    if(x&1)return x/2+1;
    else return x/2;
}

int main()
{
    //读取数据
    int n, m;
    cin>>n;
    vector<vector<int>> tree1 = vector<vector<int>>(n);
    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        tree1[a].push_back(b);
        tree1[b].push_back(a);
    }
    cin>>m;
    vector<vector<int>> tree2 = vector<vector<int>>(m);
    for (int i = 0; i < m-1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        tree2[a].push_back(b);
        tree2[b].push_back(a);
    }
    //计算最长直径与最短直径
    int t1 = getMaxLen(tree1);
    int t2 = getMaxLen(tree2);
    cout<<(t1+t2)-(divide(t1)+divide(t2));
}