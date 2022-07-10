#include "lib/leetcode.h"
using namespace std;

class Solution {
   public:
    int fillCups(vector<int>& amount) {
        int cnt = 0;
        auto q = priority_queue<int, vector<int>, less<int>>();
        for (int i : amount) if(i)q.push(i);
        while (!q.empty()) {
            int a = 0, b = 0;
            a = q.top();
            q.pop();
            if (!q.empty()) {
                b = q.top();
                q.pop();
            }
            if (a > 1) q.push(a - 1);
            if (b > 1) q.push(b - 1);
            cnt++;
        }
        return cnt;
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto arr = j.get<vector<int>>();
        print(Solution().fillCups(arr));
    }
}