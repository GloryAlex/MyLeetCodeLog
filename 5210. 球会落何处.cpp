#include "LeetCode.h"
using namespace std;

class Solution
{
private:
    int nextPosition(vector<vector<int>> &grid, int x, int y)
    {
        if (grid[x][y] > 0)
        {
            if (y != (int)grid[x].size() - 1 && grid[x][y + 1] > 0)
            {
                return y + 1;
            }
            else
                return -1;
        }
        else
        {
            if (y != 0 && grid[x][y - 1] < 0)
            {
                return y - 1;
            }
            else
                return -1;
        }
    }

public:
    vector<int> findBall(vector<vector<int>> &grid)
    {
        vector<int> ret(grid[0].size());
        for(int i=0;i<grid[0].size();i++){
            int pos=i;
            for(int j=0;j<grid.size() && pos>=0;j++){
                pos = nextPosition(grid,j,pos);
            }

            ret[i] = pos>=0?pos:-1;
        }
        return ret;
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
        print(Solution().findBall(arr));
    }
}