#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        int i=1;
        do{
            num -= i;
            i += 2;
        }while(num>0);
        return !num;
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        in >> str;
        auto num = stoi(str);
        print(Solution().isPerfectSquare(num));
    }
}