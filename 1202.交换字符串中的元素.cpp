#include "LeetCode.h"
using namespace std;

class Solution
{
    vector<int> father;
    int find(int i){
        if(father[i]<0)return i;
        else return father[i]=find(father[i]);
    }
    void unionCluster(int a,int b){
        int fa =find(a),fb=find(b);
        if(fa==fb)return;
        if(father[fa]<father[fb]){
            father[fb]+=father[fa];
            father[fa]=fb;
        }else{
            father[fa]+=father[fb];
            father[fb]=fa;
        }
    }
public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        const int length = s.length();
        father=vector<int>(length,-1);

        for(const auto& i : pairs){
            unionCluster(i[0],i[1]);
        }

        unordered_map<int, 
        priority_queue<char,vector<char>,greater<char>> > dict;

        for(int i=0;i<length;i++){
            int root = find(i);
            dict[root].push(s[i]);
        }

        for(int i=0;i<length;i++){
            int root=find(i);
            s[i]=dict[root].top();
            dict[root].pop();
        }
        return s;
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str, str2;
        in >> str >> str2;
        str = str.substr(1, str.size() - 2);
        auto matrix = getMatrix(str2);
        cout << Solution().smallestStringWithSwaps(str, matrix) << endl;
    }
}