#include "LeetCode.h"

using namespace std;

/*
pair hashcode
template <typename T, typename U>
std::size_t leetCodePairHash::operator()(const std::pair<T, U> &x) const{
    return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
}
*/

//分割字符串
vector<string> split(const string s, const char delim)
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
//去除字符串前后的引号
string getString(const string s)
{
    if (s.size() > 1 && s[0] == '"' && s.back() == '"')
        return s.substr(1, s.size() - 2);
    else return s;
}
//从形如[1.0,2.0,...]的字符串提取小数
vector<double> getDoubleArray(const string s)
{
    if (s.size() > 0 && s[0] == '[')
    {
        return getDoubleArray(s.substr(1, s.size() - 2));
    }
    vector<double> ret;
    for (auto i : split(s, ','))
    {
        ret.push_back(stod(i));
    }
    return ret;
}

//从形如[1,2,3,...]的字符串中提取字
vector<int> getArray(const string s)
{
    if (s.size() > 1 && s[0] == '[')
    {
        int len = s.back() == ']' ? s.size() - 2 : s.size() - 1;
        return getArray(s.substr(1, len));
    }
    vector<int> ret;
    for (auto i : split(s, ','))
    {
        ret.push_back(stoi(i));
    }
    return ret;
}

//从形如[[1,2,3],[1,2,3],[1,2,3]]的字符串中提取矩阵
vector<vector<int>> getMatrix(const string s)
{
    vector<vector<int>> res;
    for (auto i = s.begin(), end = s.end(); i < end;)
    {
        while (i < end && *i != '[')
            i++;
        auto j = i;
        while (j < end && *j != ']')
            j++;

        if (i == end)
            break;
        res.push_back(getArray(string(i, j + 1)));
        i = j + 1;
    }

    return res;
}

vector<string> getStringArray(const string s)
{
    if (s.size() > 1 && s[0] == '[')
        return getStringArray(s.substr(1, s.size() - 2));

    vector<string> ret = split(s, ',');
    for (auto &i : ret)
        i = i.substr(1, i.size() - 2);
    return ret;
}

//提取字符串矩阵
vector<vector<string>> getStringMatrix(const string s)
{
    vector<vector<string>> ret;
    for (auto i = s.begin() + 1, end = s.end() - 1; i != end;)
    {
        auto j = i + 1;
        while (*j != ']')
            j++;
        ret.push_back(getStringArray(string(i + 1, j)));

        i = j + 1;
        if (*i == ']' || i >= end)
            break;
        while (*i != '[')
            i++;
    }
    return ret;
}
//提取链表
ListNode* getList(string str){
    vector<int> origin = getArray(str);
    ListNode dummy=ListNode(0);
    ListNode* node = &dummy;
    for(int i:origin){
        ListNode* cur = new ListNode(i);
        node->next=cur;
        node=cur;
    }
    return dummy.next;
}
//布尔转字符串
string to_string(TreeNode *node)
{
    return "[" + serialize(node) + "]";
}
string to_string(bool value)
{
    return value ? "True" : "False";
}
string to_string(string str)
{
    return str;
}
string to_string(ListNode* node){
    string ret = "[";
    while (node)
    {
        ret+=to_string(node->val);
        ret+=",";
        node=node->next;
    }
    if(ret.back()==',')ret.back()=']';
    else ret.push_back(']');
    return ret;
}
//获取形为["a","b","c"]的数组
//二叉树序列化器
string serialize(TreeNode *root)
{
    string str;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (node == NULL)
            str += "null,";
        else
        {
            str += to_string(node->val);
            str.push_back(',');
            q.push(node->left);
            q.push(node->right);
        }
    }
    str.pop_back();
    return str;
}
string getNextItem(string &data, int &pos)
{
    int temp = pos, end = pos;
    while (data[end] != ',')
        end++;
    pos = end + 1;
    return string(data.begin() + temp, data.begin() + end);
}
TreeNode *deserialize(string data)
{
    if (data.size() && data[0] == '[')
        return deserialize(data.substr(1, data.size() - 2));

    data.push_back(',');
    TreeNode *root = NULL;
    queue<TreeNode *> q;

    /*读取root*/
    int pos = 0;
    string item = getNextItem(data, pos);
    if (item == "null")
        return NULL;
    else
        root = new TreeNode(stoi(item));

    /*读取剩余结点*/
    q.push(root);
    while (pos != data.size())
    {
        TreeNode *node = q.front();
        q.pop();

        item = getNextItem(data, pos);
        if (item != "null")
        {
            node->left = new TreeNode(stoi(item));
            q.push(node->left);
        }

        if (pos == data.size())
            break;

        item = getNextItem(data, pos);
        if (item != "null")
        {
            node->right = new TreeNode(stoi(item));
            q.push(node->right);
        }
    }
    return root;
}