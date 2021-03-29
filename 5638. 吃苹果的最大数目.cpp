#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    int eatenApples(vector<int> &apples, vector<int> &days)
    {
        int calendar[100000] = {0};
        int lastDay = 0;
        int count = 0;
        for (int i = 0; i < days.size(); i++)
        {
            if (apples[i])
            {
                calendar[i + days[i] - 1] += apples[i];
                lastDay = max(lastDay, i + days[i] - 1);
            }

            for (int j = i; j <= lastDay; j++)
            {
                if (calendar[j])
                {
                    count++;
                    calendar[j]--;
                    break;
                }
            }
        }

        for (int i = days.size(); i <= lastDay; i++)
        {
            for (int j = i; j <= lastDay; j++)
            {
                if (calendar[j])
                {
                    count++;
                    calendar[j]--;
                    break;
                }
            }
        }

        return count;
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str, str2;
        in >> str >> str2;
        auto arr = getArray(str);
        auto arr2 = getArray(str2);
        cout << Solution().eatenApples(arr, arr2) << endl;
    }
}