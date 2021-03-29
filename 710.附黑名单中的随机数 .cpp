#include "LeetCode.h"
using namespace std;

class Solution
{
    int n;
    unordered_map<int,int> dict;
public:
    Solution(int N, vector<int> &blacklist)
    {
        unordered_set<int> black(blacklist.begin(),blacklist.end());
        n = N-blacklist.size();

        int cur = n;
        for(int i:blacklist){
            if(i>n)continue;
            while(black.count(cur))cur++;
            dict[i]=cur++;
        }

        srand(time(NULL));
    }

    int pick()
    {
        int position = rand()%n;
        if(dict.count(position))return dict[position];
        else return position;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        int n;
        string str;
        in >> n >> str;
        auto arr = getArray(str);

        Solution solution(n, arr);
        for(int i=0;i<10;i++)cout<<solution.pick()<<' ';
    }
}