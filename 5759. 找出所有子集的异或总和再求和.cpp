#include "LeetCode.h"
using namespace std;

class Solution {
    int sum=0;
    void getSubsetXorSum(vector<int>& nums,int index,int cur){
        int holdCur = cur^nums[index];
        if(index==(int)nums.size()-1){
            sum+=cur;
            sum+=holdCur;
        }else {
            getSubsetXorSum(nums,index+1,cur);
            getSubsetXorSum(nums,index+1,holdCur);
        }
    }
   public:
    int subsetXORSum(vector<int>& nums) {
        getSubsetXorSum(nums,0,0);
        return sum;
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = getArray(str);
        cout << Solution().subsetXORSum(arr) << endl;
    }
}