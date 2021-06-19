#include "LeetCode.h"
using namespace std;

class Solution {
   public:
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        sort(heaters.begin(), heaters.end());
        sort(houses.begin(), houses.end());
        // TODO:
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str, s2;
        in >> str >> s2;
        auto houses = getArray(str);
        auto heaters = getArray(s2);
        cout << Solution().findRadius(houses, heaters) << endl;
    }
}