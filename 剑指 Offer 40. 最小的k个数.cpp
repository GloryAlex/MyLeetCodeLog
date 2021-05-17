#include "LeetCode.h"
using namespace std;
class Solution {
   public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        auto q = priority_queue<int>();
        for(int i:arr){
            q.push(i);
            if(q.size()>k)q.pop();
        }
        vector<int> ret;
        while(q.size()){
            ret.push_back(q.top());
            q.pop();
        }
        return ret;
        //TODO: 完成快排解法
    }
};
int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        int k;
        in >> str >> k;
        auto arr = getArray(str);
        print(Solution().getLeastNumbers(arr, k));
    }
}