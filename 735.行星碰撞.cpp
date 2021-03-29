#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> remainAsteroidList;
        for (int asteroid : asteroids)
        {
            if (asteroid > 0)
                remainAsteroidList.emplace_back(asteroid);
            else
            {
                int realSize = -asteroid;
                while (remainAsteroidList.size() && remainAsteroidList.back() > 0 && remainAsteroidList.back() < realSize)
                    remainAsteroidList.pop_back();
                
                if(remainAsteroidList.empty() || remainAsteroidList.back()<0)remainAsteroidList.emplace_back(asteroid);
                else if(remainAsteroidList.back()==realSize)remainAsteroidList.pop_back();
            }
        }
        return remainAsteroidList;
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        in >> str;
        auto arr = getArray(str);
        print(Solution().asteroidCollision(arr));
    }
}