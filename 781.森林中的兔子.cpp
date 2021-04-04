#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        unordered_map<int, int> colorRabitCount;
        int total = 0;
        for (int i : answers)
        {
            if (i)
                colorRabitCount[i]++;
            else
                total++;
        }
        for (const auto &[x,y] : colorRabitCount)
        {
            total += (x+y)/(x+1)*(x+1);
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
        auto arr = getArray(str);
        print(Solution().numRabbits(arr));
    }
}