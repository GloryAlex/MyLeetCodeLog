#include "LeetCode.h"
using namespace std;

struct classPoint
{
    double pass;
    double total;
    classPoint(int pass, int total)
    {
        this->pass = pass;
        this->total = total;
    }
    void add()
    {
        pass++;
        total++;
    }
    double getValue(){
        return (double)pass/(double)total;
    }
    const bool operator<(const classPoint &b) const
    {
        return (double)(total-pass) / (double)(total + total * total) < (double)(b.total-b.pass) / (double)(b.total + b.total * b.total);
    }
};
class Solution
{
public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        priority_queue<classPoint> q;
        for(auto& i:classes){
            q.push(classPoint(i[0],i[1]));
        }

        for(int _=0;_<extraStudents;_++){
            auto cur = q.top();q.pop();
            cur.add();

            q.push(cur);
        }

        double res = 0.0;
        while(q.size()){
            auto cur = q.top();q.pop();
            res += cur.getValue();
        }
        return res/classes.size();
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        in >> str;
        auto classes = getMatrix(str);
        int n;
        in >> n;
        cout << Solution().maxAverageRatio(classes, n) << endl;
    }
}