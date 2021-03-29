#include "LeetCode.h"
using namespace std;

class Solution
{
private:
    unordered_map<string,int> number;
    vector<unordered_map<int,double>> graph;
    inline int getId(const string& name){
        if(!number.count(name)){
            number[name]=graph.size();
            graph.push_back({});
        }
        return number[name];
    }
    double query(const string& _source,const string& _destination){
        if(!number.count(_destination) || !number.count(_source))return -1.0;
        queue<pair<int,double>> q;

        int source = getId(_source),destination = getId(_destination);
        q.push({source,1.0});
        vector<int> hasVisited(graph.size());
        while(!q.empty()){
            int cur = q.front().first;
            double curCost = q.front().second;
            if(cur==destination)return curCost;

            hasVisited[cur]=true;
            q.pop();
            for(const auto& i:graph[cur]){
                if(!hasVisited[i.first]) q.push({i.first,curCost*i.second});
            }
        }

        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        for(int i=0;i<equations.size();i++){
            int source = getId(equations[i][0]),destination=getId(equations[i][1]);
            graph[source][destination]=values[i];
            graph[destination][source]=(1/values[i]);

            //cout<<(1/values[i])<<' '<<graph[destination][source]<<endl;
        }

        vector<double> ret(queries.size());
        for(int i=0;i<queries.size();i++){
            ret[i]=query(queries[i][0],queries[i][1]);
        }

        return ret;
    }
};

int main()
{
    vector<vector<string>>
        equations = {{"a","b"},{"b","c"}},
        queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    vector<double> values = {2.0,3.0}; 

    print(Solution().calcEquation(equations,values,queries));
}