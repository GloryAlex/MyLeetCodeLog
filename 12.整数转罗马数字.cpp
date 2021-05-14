#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution
{
public:
    string intToRoman(int num)
    {
        int values[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string replaces[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        string ret = "";

        int position = 0;
        while(num){
            while(num%values[position]==num)position++;
            int repeatTimes = num/values[position];
            for(int i=0;i<repeatTimes;i++)ret+=replaces[position];

            num%=values[position];
        }
        return ret;
    }
};
// @lc code=end

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        int s;
        in >> s;
        print(Solution().intToRoman(s));
    }
}