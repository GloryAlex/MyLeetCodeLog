#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>

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
vector<int> getArray(string s){
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
    typedef vector<int>::iterator vp;
    inline void swap(vp a,vp b){
        int c= *a;
        *a=*b;
        *b=c;
    }
    inline void reverse(vp l,vp r){
        while(l<r){
            swap(l++,r--);
        }
    }
public:
    void nextPermutation(vector<int>& nums) {
        const int length=nums.size();
        if(length<2)return ;
        int i=length-2;
        while(i>=0){
            if(nums[i]<nums[i+1])break;
            else i--;
        }

        if(i>=0){
            int j=length-1;
            while(j>=0){
                if(nums[j]>nums[i])break;
                else j--;
            }
            swap(nums.begin()+i,nums.begin()+j);
        }
        reverse(nums.begin()+i+1,nums.end()-1);
    }
};

int main(){
    ifstream in("input");
    while(!in.eof()){
        string str;
        in>>str;
        auto arr = getArray(str);
        Solution().nextPermutation(arr);
        for(auto i:arr)cout<<i<<' ';
        cout<<endl;
    }
}