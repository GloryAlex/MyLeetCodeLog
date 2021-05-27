#include "LeetCode.h"
using namespace std;

/**
 * [5,2,6,1,3] -> false
 * [5,2,1,3,6] -> true
 */
class Solution {
   public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> orderStack;
        int prevElement = INT_MIN;
        for (int i : preorder) {
            if (i < prevElement) return false;
            while (!orderStack.empty() && orderStack.top() < i) {
                prevElement = orderStack.top();
                orderStack.pop();
            }
            orderStack.push(i);
        }
        return true;
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = getArray(str);
        print(Solution().verifyPreorder(arr));
    }
}