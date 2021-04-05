#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <queue>
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;

string getString(const string s);
vector<string> split(string s, const char delim);
vector<int> getArray(string s);
vector<vector<int>> getMatrix(const string s);
vector<string> getStringArray(const string s);
vector<double> getDoubleArray(const string s);
vector<vector<string>> getStringMatrix(const string s);

//二叉树结构
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//一些常用的泛型函数
string to_string(bool value);
string to_string(string str);
string to_string(TreeNode* node);

//将vector<T>转为字符串
template <typename T>
string to_string(vector<T> a)
{
    string s = "[";
    for (auto i : a)
        s += to_string(i) + ",";

    if (a.empty())
        s += ']';
    else
        s.back() = ']';

    return s;
}
//打印特定类型, 打印结果由to_string函数实现
template <typename T>
inline void print(const T a, const string end = "\n")
{
    cout << to_string(a) << end;
}

//用于pair的哈希类
struct leetCodePairHash
{
public:
    template <typename T, typename U>
    size_t operator()(const pair<T, U> &x) const
    {
        return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
    }
};

string serialize(TreeNode *root);
string getNextItem(string &data, int &pos);
TreeNode *deserialize(string data);

#endif