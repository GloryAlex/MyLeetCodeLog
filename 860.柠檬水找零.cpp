#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveCount=0,tenCount=0;
        for(int i:bills){
            if(i==5)fiveCount++;
            else if(i==10){
                fiveCount--;
                tenCount++;
            }else if(i==20){
                if(tenCount>0){
                    fiveCount--;
                    tenCount--;
                }else{
                    fiveCount -= 3;
                }
            }

            if(fiveCount<0||tenCount<0)return false;
        }
        return true;
    }
};

int main()
{
    ifstream in;
    in.open("input");
    while(!in.eof()){
        string s;
        in>>s;
        auto arr=getArray(s);
        print(Solution().lemonadeChange(arr));
    }
}