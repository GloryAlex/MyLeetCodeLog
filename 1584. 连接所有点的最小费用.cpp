#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    class JointCluster
    {
    public:
        vector<int> father;
        int size;
        JointCluster(int i) : father(vector<int>(i, -1)), size(i) {}
        int find(int i)
        {
            return father[i] < 0 ? i : father[i] = find(father[i]);
        }
        void join(int x, int y)
        {
            x = find(x), y = find(y);
            if (x == y)
                return;

            if (father[x] <= father[y])
            {
                father[x] += father[y];
                father[y] = x;
            }
            else
            {
                father[y] += father[x];
                father[x] = y;
            }
            size--;
        }
    };
    struct Edge{
        int source;
        int destination;
        int length;
        const bool operator<(const Edge& b)const{
            return length<b.length;
        }
    };
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        vector<Edge> edges;
        for(int i=0,len=points.size();i<len;i++){
            for(int j=i+1;j<len;j++){
                edges.push_back({
                    i,j,abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])
                });
            }
        }

        sort(edges.begin(),edges.end());
        JointCluster jCluster(points.size());
        int total = 0;

        for(const auto& edge:edges){
            if(jCluster.find(edge.source)!=jCluster.find(edge.destination)){
                jCluster.join(edge.source,edge.destination);
                total+=edge.length;

                if(!jCluster.size)break;
            }
        }

        return total;
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
        
        cout << Solution().minCostConnectPoints(matrix) << endl;
    }
}