#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    string reformatNumber(string number)
    {
        if(number.size()<=3)return number;
        int length = 0;
        for(char i:number){
            if(i>='0'&&i<='9')number[length++]=i;
        }
        number.resize(length);
        
        string ret;
        for(int i=0;i<(length/3)*3;i+=3){
            ret += number.substr(i,3);
            ret += '-';
        }
        ret.pop_back();
        
        if(length%3==1){
            char temp = ret.back();
            ret.back()='-';
            ret.push_back(temp);
            ret.push_back(number.back());
        }else if(length%3==2){
            if(number.size()>2)ret+="-";
            ret += number.substr(length-2,2);
        }

        return ret;
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        getline(in,str);
        str = str.substr(1, str.size() - 2);
        cout << Solution().reformatNumber(str) <<endl;
    }
}