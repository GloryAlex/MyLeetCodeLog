#include "LeetCode.h"
using namespace std;

class Solution {
private:
    string::iterator begin,end;
    vector<long long> list;
    void init(string& s){
        begin=s.begin();
        end=s.end();
        list.resize(0);
    }
    inline int getLastSum(){
        return list.back()+*(list.rbegin()+1);
    }
    bool backtack(string::iterator cur){
        if(cur==end && list.size()>2)return true;
        if(*cur=='0'){
            if(list.size()<2||(list.back()+*(list.rbegin()+1)==0)){
                list.push_back(0);
                if(backtack(cur+1))return true;
                list.pop_back();
            }
            return false;
        }

        for(auto i=cur+1;i<=end;i++){
            long long temp=stoll(string(cur,i));
            if(temp<INT_MAX && (list.size()<2||getLastSum()==temp)){
                list.push_back(temp);
                if(backtack(i))return true;
                else list.pop_back();
            }else if(temp>INT_MAX){
                //cut
                break;
            }else if(list.size()>2&&getLastSum()<temp){
                //cut
                break;
            }else{
                //do nothing
            }
        }

        return false;
    }
    vector<int> toInt(vector<long long> t){
        vector<int> ret(t.size());
        for(int i=0;i<t.size();i++)ret[i]=(int)t[i];
        return ret;
    }
public:
    vector<int> splitIntoFibonacci(string s) {
        init(s);
        if(backtack(s.begin())){
            return toInt(list);
        }else return vector<int>{};
    }
};


int main()
{
    ifstream in("input");
    while(!in.eof())
    {
        string str;
        in >> str;
        print(Solution().splitIntoFibonacci(str.substr(1,str.size()-2)));
    }
}