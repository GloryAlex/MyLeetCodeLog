#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret = {-1,-1};
        if(!nums.empty()){
            const auto l = nums.begin(),r=nums.end();
            auto firstMatch = firstMatchBinarySearch(l,r,target);
            auto lastMatch = lastMatchBinarySearch(l,r,target);
            if(*firstMatch==target){
                ret[0]=(int)(firstMatch-l);
                ret[1]=(int)(lastMatch-l);
            }
        }
        return ret;
    }

    vector<int>::iterator firstMatchBinarySearch(vector<int>::iterator left,vector<int>::iterator right,int target){
        while (left<right)
        {
            auto mid = left + (right-left)/2;
            if(*mid<target)left = mid+1;
            else right = mid;
        }
        return left;
    }

    vector<int>::iterator lastMatchBinarySearch(vector<int>::iterator left,vector<int>::iterator right,int target){
        while (left<right)
        {
            auto mid = left + (right-left)/2;
            if(*mid<=target)left = mid+1;
            else right = mid;
        }
        return left-1;
    }
};

int main()
{
    ifstream in("input");
    string str;
    int target;
    while(!in.eof())
    {
        in>>str>>target;
        auto arr = getArray(str);
        auto res = Solution().searchRange(arr,target);

        print(res);
    }
}