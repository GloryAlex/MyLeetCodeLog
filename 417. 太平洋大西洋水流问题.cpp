#include "LeetCode.h"

using namespace std;

class Solution {
private:
    int rowLen,colLen;
    vector<vector<int>> visited;
    vector<pair<int,int>> direct{{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<int>> ret;
    inline bool isValid(int x,int y){
        return x>=0&&y>=0&&x<rowLen&&y<colLen;
    }
    void pacificDfs(int x,int y,const vector<vector<int>>& matrix){
        visited[x][y] = 1;

        for(auto i:direct){
            int newX = x + i.first;
            int newY = y + i.second;
            if(isValid(newX,newY) && !visited[newX][newY])
                if(matrix[x][y] <= matrix[newX][newY])
                    pacificDfs(newX,newY,matrix);
        }
    }

    void AtlanticDfs(int x,int y,const vector<vector<int>>& matrix){
        if(visited[x][y]==1)ret.push_back({x,y});
        visited[x][y] = -1;

        for(auto i:direct){
            int newX = x+i.first;
            int newY = y+i.second;
            if(isValid(newX,newY) && visited[newX][newY]!=-1)
                if(matrix[x][y] <= matrix[newX][newY])
                    AtlanticDfs(newX,newY,matrix);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.empty()||matrix[0].empty())return {};

        rowLen = matrix.size(),colLen=matrix[0].size();
        visited = vector<vector<int>>(rowLen,vector<int>(colLen,0));
        ret.resize(0);

        for(int i=0;i<rowLen;i++)pacificDfs(i,0,matrix);
        for(int i=0;i<colLen;i++)pacificDfs(0,i,matrix);

        for(int i=0;i<rowLen;i++)AtlanticDfs(i,colLen-1,matrix);
        for(int i=0;i<colLen;i++)AtlanticDfs(rowLen-1,i,matrix);

        return ret;
    }
};

int main(){
    ifstream in("input");
    while(!in.eof()){
        string str;
        in>>str;
        auto matrix = getMatrix(str);
        matrix = Solution().pacificAtlantic(matrix);
        for(auto &i:matrix){
            printf("[%d,%d],",i[0],i[1]);
        }
        putchar('\n');
    }
}