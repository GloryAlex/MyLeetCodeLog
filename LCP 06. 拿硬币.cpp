#include "LeetCode.h"
using namespace std;

class Solution {
public:
    int minCount(vector<int>& coins) {
        int total = 0;
        for(int i:coins){
            total+=(i+1)/2;
        }
        return total;
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = getArray(str);
        print(Solution().minCount(arr));
    }
}