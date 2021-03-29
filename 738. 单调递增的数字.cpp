#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    int monotoneIncreasingDigits(int N)
    {
        string str = to_string(N);

        int end = str.size();
        for(int i=end-1;i>0;i--){
            if(str[i]<str[i-1]){
                end = i;
                str[i-1]--;
            }
        }
        for(int i=end;i<str.size();i++){
            str[i]='9';
        }
        return stoi(str);
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        int n;
        in >> n;
        n = Solution().monotoneIncreasingDigits(n);
        print(n);
    }
}