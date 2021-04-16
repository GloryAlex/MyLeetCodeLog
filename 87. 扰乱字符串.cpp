#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    bool isScramble(string s1, string s2)
    {
        if (s1.length() != s2.length())
            return false;
        int length = s1.length();
        vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(length, vector<vector<int>>(length, vector<int>(length + 1)));
        for (int i = 0; i < length; i++)
            for (int j = 0; j < length; j++)
                dp[i][j][1] = (s1[i] == s2[j]);

        for(int tempLen=2;tempLen<=length;tempLen++){
            for(int i=0;i<=length-tempLen;i++){
                for(int j=0;j<=length-tempLen;j++){
                    for(int k=1;k<=tempLen-1;k++){
                        //划分s1->t1,s2->t2
                        if((dp[i][j][k] && dp[i+k][j+k][tempLen-k]) ||
                        //划分s1->t2,s2->t1
                        (dp[i][j+tempLen-k][k] && dp[i+k][j][tempLen-k])){
                            dp[i][j][tempLen]=true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][0][length];
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string s1, s2;
        in >> s1 >> s2;
        s1 = getString(s1);
        s2 = getString(s2);
        print(Solution().isScramble(s1, s2));
    }
}