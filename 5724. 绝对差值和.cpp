#include "LeetCode.h"
#include <set>
using namespace std;

class Solution
{
    const int MOD = 1e9 + 7;
public:
    int minAbsoluteSumDiff(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1 == nums2)
            return 0;
        set<int> dict = set<int>(nums1.begin(), nums1.end());

        int maxCanReduce = 0;
        long long diff = 0;
        for(int len=nums1.size(),i=0;i<len;i++){
            int curDiff = abs(nums1[i]-nums2[i]);

            auto largeIndex=upper_bound(dict.begin(),dict.end(),nums2[i]);
            maxCanReduce = max(maxCanReduce,abs(curDiff-abs(*largeIndex-nums2[i])));
            if(largeIndex!=dict.begin()){
                largeIndex--;
                maxCanReduce = max(maxCanReduce,abs(curDiff-abs(*largeIndex-nums2[i])));
            }
            diff+=curDiff;
            diff%=MOD;
        }
        return diff-maxCanReduce;
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str, s2;
        in >> str >> s2;
        auto arr = getArray(str);
        auto arr2 = getArray(s2);
        cout << Solution().minAbsoluteSumDiff(arr, arr2) << endl;
    }
}