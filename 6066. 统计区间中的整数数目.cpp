#include "lib/leetcode.h"
using namespace std;

class CountIntervals {
    map<int, int> rightLeft;
    int cnt = 0;

   public:
    CountIntervals() {}

    void add(int left, int right) {
        for (auto it = rightLeft.lower_bound(left);
             it != rightLeft.end() && it->second <= right;) {
            left = min(left, it->second);
            right = max(right, it->first);
            cnt -= (it->first - it->second + 1);
            it = rightLeft.erase(it);
        }
        rightLeft.insert(make_pair(right, left));
        cnt += (right - left + 1);
    }

    int count() { return cnt; }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto ops = j.get<vector<string>>();
        in >> j >> ws;
        auto args = j.get<vector<vector<int>>>();
        CountIntervals c = CountIntervals();
        for (int i = 1; i < ops.size(); i++) {
            if (ops[i] == "add")
                c.add(args[i][0], args[i][1]);
            else
                print(c.count(), ",");
        }
    }
}