#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>
#include <sstream>
#include <fstream>
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

class Solution
{
    unordered_map<int,int> numOf1;
    int getNumOfOne(int num){
        int sum=0;
        while(num){
            num&=(num-1);
            sum++;
        }
        return sum;
    }
public:
    vector<int> sortByBits(vector<int> &arr)
    {
        for(auto i:arr)
            if(!numOf1.count(i))
                numOf1[i]=getNumOfOne(i);
        sort(arr.begin(), arr.end(),[&](int x,int y){
            int nx = numOf1[x];
            int ny = numOf1[y];
            if(nx==ny)return x<y;
            else return nx<ny;
        });
        return arr;
    }
};
string to_string(const vector<int> &arr)
{
    string str = "[";
    for (auto i : arr)
        str += to_string(i) + ",";
    if (str.size() >= 1)
        str.back() = ']';
    return str;
}
int main()
{
    ifstream in("./input");
    while (!in.eof())
    {
        string str;
        in >> str;
        auto arr = getArray(str);
        arr = Solution().sortByBits(arr);
        cout << to_string(arr);
    }
}