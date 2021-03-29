#include "LeetCode.h"
#include <numeric>
using namespace std;

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        k = cardPoints.size() - k;

        int cur = 0, score = INT_MAX;
        for (int i = 0; i < k; i++)
            cur += cardPoints[i];

        for (int i = k; i < cardPoints.size(); i++)
        {
            score = min(cur, score);
            cur -= cardPoints[i - k];
            cur += cardPoints[i];
        }
        score = min(cur, score);
        return accumulate(cardPoints.begin(),cardPoints.end(),0)-score;
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
        int k;
        in >> k;
        cout << Solution().maxScore(arr, k) << endl;
    }
}