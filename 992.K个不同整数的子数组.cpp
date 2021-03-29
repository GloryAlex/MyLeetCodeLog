#include "LeetCode.h"
using namespace std;

class Solution
{
    int mostSubarraysWithKDistinct(vector<int>& a,int k){
        int left = 0,right=0;
        vector<int> counter=vector<int>(a.size()+1);

        int total = 0,curKind=0;
        while(right<a.size()){
            if(!(counter[a[right]]++))curKind++;
            right++;

            while(curKind>k){
                if(!--counter[a[left]])curKind--;
                left++;
            }
            total+=right-left;
        }
        return total;
    }
public:
    int subarraysWithKDistinct(vector<int> &A, int K)
    {
        return mostSubarraysWithKDistinct(A,K)-mostSubarraysWithKDistinct(A,K-1);
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        in >> str;
        auto arr = getArray(str);
        int k;
        in >> k;
        cout << Solution().subarraysWithKDistinct(arr, k) << endl;
    }
}