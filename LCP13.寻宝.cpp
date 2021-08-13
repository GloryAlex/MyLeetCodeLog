#include "LeetCode.h"
using namespace std;

class Solution {
    const vector<pair<int, int>> directions = { {0,1},{1,0},{0,-1},{-1,0} };
public:
    int minimalSteps(vector<string>& maze) {
        //TODO:完成寻宝
        return 0;
    }
};
int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto maze = getStringArray(str);
        print(Solution().minimalSteps(maze));
    }
}