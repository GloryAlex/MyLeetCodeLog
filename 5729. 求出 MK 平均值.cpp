#include "LeetCode.h"
using namespace std;

class MKAverage
{
    int m, k;
    queue<int> q;
    multiset<int> nums;

public:
    MKAverage(int m, int k)
    {
        this->m = m;
        this->k = k;
    }
    void addElement(int num)
    {
        q.push(num);
        nums.insert(num);
        if (q.size() > m)
        {
            int lastElement = q.front();
            q.pop();
            nums.erase(nums.find(lastElement));
        }
    }

    int calculateMKAverage()
    {
        if (q.size() < m)
            return -1;
        long long size = m - 2 * k;
        auto i = nums.begin();
        for (int j = 0; j < k; j++)
            i++;

        long long total = 0;
        for (int j = 0; j < size; j++)
        {
            total += *i;
            i++;
        }
        return total / size;
    }
};

int main()
{
    int m, k;
    cin >> m >> k;
    MKAverage mk = MKAverage(m, k);
    while (1)
    {
        string op;
        cin >> op;
        if (op == "add")
        {
            cin >> k;
            mk.addElement(k);
        }
        else
        {
            cout << mk.calculateMKAverage();
        }
    }
}