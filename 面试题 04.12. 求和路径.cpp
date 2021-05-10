#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    int pathSum(TreeNode *root, int sum)
    {
        //TODO
    }};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        in >> str;
        auto arr = deserialize(str);
        int sum;
        in >> sum;
        cout << Solution().pathSum(arr, sum) << endl;
    }
}