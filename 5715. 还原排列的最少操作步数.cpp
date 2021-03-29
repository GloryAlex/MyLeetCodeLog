#include "LeetCode.h"
using namespace std;

class Solution
{
    bool check(vector<int> &arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] != i)
                return false;
        }
        return true;
    }
    int test(int n)
    {
        vector<int> perm = vector<int>(n);
        for (int i = 0; i < n; i++)
            perm[i] = i;
        vector<int> arr = vector<int>(n);

        int total = 0;
        while (!check(arr))
        {
            total++;
            for (int i = 0; i < n; i++)
            {
                if (i % 2 == 0)
                    arr[i] = perm[i / 2];
                else
                    arr[i] = perm[n / 2 + (i - 1) / 2];
            }
            perm = arr;
        }
        return total;
    }

public:
    int reinitializePermutation(int n)
    {
        return test(n);
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        int str;
        in >> str;
        cout << Solution().reinitializePermutation(str)<<endl;
    }
}