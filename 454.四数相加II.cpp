#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

//分割字符串
vector<string> split(string s, const char delim)
{
    vector<string> tokens;
    istringstream iss(s);
    string temp;

    while (getline(iss, temp, delim))
    {
        if (temp.size())
        {
            tokens.push_back(temp);
        }
    }
    return tokens;
}
//从形如[1,2,3,...]的字符串中提取字
vector<int> getArray(string s)
{
    if (s.size() > 0 && s[0] == '[')
    {
        return getArray(s.substr(1, s.size() - 1));
    }
    vector<int> ret;
    for (auto i : split(s, ','))
    {
        ret.push_back(stoi(i));
    }
    return ret;
}

class Solution {
private:
    unordered_map<int,int> getAllSum(vector<int>& A,vector<int>& B){
        unordered_map<int,int> res1;
        const int length = A.size();
        for(int i=0;i<length;i++){
            for(int j=0;j<length;j++){
                res1[A[i]+B[j]]++;
            }
        }
        return res1;
    }
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        auto res1 = getAllSum(A,B);
        int count = 0;
        for(int i=0,length = A.size();i<length;i++){
            for(int j=0;j<length;j++){
                int value = -(C[i]+D[j]);
                if(res1.count(value))
                    count += res1[value];
            }
        }
        return count;
    }
};

int main(){
    ifstream in("input");
    while(!in.eof()){
        vector<vector<int>> list(4);
        string str;
        for(int i=0;i<4;i++){
            in>>str;
            list[i]=getArray(str);
        }
        cout<<Solution().fourSumCount(list[0],list[1],list[2],list[3])<<endl;
    }
}