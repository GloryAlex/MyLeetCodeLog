#include "LeetCode.h"
using namespace std;
class Solution {
   public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left = 1,
            right = INT_MAX;
        if (dist.size()-1 > hour) return -1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canAccess(dist, (double)mid, hour))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
    bool canAccess(vector<int>& dist, double velocity, double hour) {
        double timeCost = 0;
        for (int i : dist) {
            timeCost = ceil(timeCost);
            timeCost += (double)i / velocity;
        }
        return timeCost <= hour;
    }
};
int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        double hour;
        in >> str >> hour;
        auto arr = getArray(str);
        cout << Solution().minSpeedOnTime(arr, hour) << endl;
    }
}