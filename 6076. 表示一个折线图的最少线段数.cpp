#include "lib/leetcode.h"
using namespace std;

class Solution {
    struct Point {
        long x, y;
        Point(long x, long y) {
            this->x = x;
            this->y = y;
        };
        Point getTan(Point& b) {
            if (x < b.x) return b.getTan(*this);
            auto xo = x - b.x;
            auto yo = y - b.y;
            if (yo == 0)
                return Point(1, 0);
            else {
                auto d = gcd(xo, yo);
                return Point(xo / d, yo / d);
            }
        };
        bool operator==(const Point b)const { return x == b.x && y == b.y; }
        bool operator<(const Point b)const { return x < b.x; }
        static Point of(vector<int>& v) { return Point(v[0], v[1]); }
    };

   public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        if (stockPrices.size() <= 1) return 0;
        vector<Point> arr;
        arr.reserve(stockPrices.size());
        for (auto& i : stockPrices) {
            arr.push_back(Point::of(i));
        }
        sort(arr.begin(),arr.end());

        int total=1;
        auto tan=arr[1].getTan(arr[0]);
        for(int i=2;i<arr.size();i++){
            auto cur=arr[i].getTan(arr[i-1]);
            if(!(cur==tan)){
                tan=cur;
                total++;
            }
        }
        return total;
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto s = j.get<vector<vector<int>>>();
        print(Solution().minimumLines(s));
    }
}