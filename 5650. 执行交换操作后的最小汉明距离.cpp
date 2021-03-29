#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    int minimumHammingDistance(vector<int> &source, vector<int> &target, vector<vector<int>> &allowedSwaps)
    {
        const int cityNums = source.size();
        vector<int> father(cityNums, -1);

        function<int(int)> find = [&](int x) {
            return father[x] < 0 ? x : father[x] = find(father[x]);
        };
        auto unionCluster = [&](int x, int y) {
            int fx = find(x), fy = find(y);
            if (fx == fy)
            {
                return;
            }
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
    
        for(const auto& i:allowedSwaps){
            unionCluster(i[0],i[1]);
        }

        unordered_map<int,unordered_map<int,int>> allElements;
        for(int i=0;i<cityNums;i++){
            int root = find(i);
            allElements[root][source[i]]++;
        }

        int total = 0;
        for(int i=0;i<cityNums;i++){
            int cur = target[i],root=find(i);
            if(allElements[root][cur]>0){
                allElements[root][cur]--;
            }else total++;
        }
        return total;
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str, str2, str3;
        in >> str >> str2 >> str3;
        auto arr = getArray(str);
        auto target = getArray(str2);
        auto matrix = getMatrix(str3);
        cout << Solution().minimumHammingDistance(arr, target, matrix) << endl;
    }
}