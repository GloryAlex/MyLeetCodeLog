#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=587 lang=cpp
 *
 * [587] 安装栅栏
 */

// @lc code=start
class Solution {
    struct line {
        int x;
        int y;

        line() : x(0), y(0) {}
        line(int _x, int _y) : x(_x), y(_y) {}
        line(vector<int>& v) {
            this->x = v[0];
            this->y = v[1];
        }
        bool operator<(const line b) const {
            if (x != b.x)
                return x < b.x;
            else
                return y < b.y;
        }
        line operator-(const line b) { return line(x - b.x, y - b.y); }
        double operator*(const line b) const { return x * b.y - y * b.x; }
        double area(line b, line c) const {
            return (b - (*this)) * (c - (*this));
        }
        vector<int> toVector() { return vector<int>{x, y}; }
    };

   public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        vector<line> treePoints(n);
        transform(trees.begin(), trees.end(), treePoints.begin(),
                  [](vector<int>& a) { return line(a); });
        sort(treePoints.begin(), treePoints.end());

        int topId = 1;
        vector<int> stack(n + 10);
        vector<int> hasVisit(n + 10);
        for (int i = 1; i < n; i++) {
            auto c = treePoints[i];
            while (topId >= 2) {
                auto a = treePoints[stack[topId - 1]],
                     b = treePoints[stack[topId]];
                if (a.area(b, c) < 0)
                    hasVisit[stack[topId--]] = false;
                else
                    break;
            }
            stack[++topId] = i;
            hasVisit[i] = true;
        }

        int size = topId;
        for (int i = n - 1; i >= 0; i--) {
            if (hasVisit[i]) continue;
            auto c = treePoints[i];
            while (topId > size) {
                auto a = treePoints[stack[topId - 1]],
                     b = treePoints[stack[topId]];
                if (a.area(b, c) < 0)
                    topId--;
                else
                    break;
            }
            stack[++topId] = i;
        }
        vector<vector<int>> ans;
        for (int i = 1; i < topId; i++)
            ans.push_back(treePoints[stack[i]].toVector());
        return ans;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto trees = j.get<vector<vector<int>>>();
        print(Solution().outerTrees(trees));
    }
}