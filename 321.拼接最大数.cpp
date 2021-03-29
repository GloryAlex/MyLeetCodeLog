#include "LeetCode.h"

using namespace std;

class Solution {
private:
    typedef vector<int> array;
    typedef vector<int>::iterator p;
    //@return: if first larger than second
    inline bool compare(p i,p iend,p j,p jend){
        while(i!=iend && j!=jend){
            if(*i!=*j)return *i>*j;
            else i++,j++;
        }

        return i!=iend;
    }
public:
    array getMaxKSequence(array& nums, int k){
        array ret(k);
        ret.resize(0);

        int remain = (int)nums.size()-k;
        for(auto i:nums){
            while(!ret.empty() && ret.back()<i && remain){
                ret.pop_back();
                remain--;
            }

            if(ret.size()<k)ret.push_back(i);
            else remain--;
        }

        return ret;
    }
    vector<int> merge(vector<int>& nums1,vector<int>& nums2){
        vector<int> ret(nums1.size()+nums2.size());
        ret.resize(0);

        auto end1=nums1.end(),end2=nums2.end();
        auto i=nums1.begin(),j=nums2.begin(); 
        while(i<end1&&j<end2){
            if(compare(i,end1,j,end2))ret.push_back(*i++);
            else ret.push_back(*j++);
        }

        while(i<end1)ret.push_back(*i++);
        while(j<end2)ret.push_back(*j++);

        return ret;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1 = nums1.size(),len2 = nums2.size();

        vector<int> ret,max1,max2,mergeAns;
        for(int x=0,y=k-x;x<=len1 && y>=0;x++,y--){
            if(y>len2)continue;

            max1 = getMaxKSequence(nums1,x);
            max2 = getMaxKSequence(nums2,y);
            
            mergeAns = merge(max1,max2);
            if(!compare(ret.begin(),ret.end(),mergeAns.begin(),mergeAns.end()))
                ret=mergeAns;
        }
        return ret;
    }
};

int main()
{
    ifstream in("input");
    string str1,str2;
    int k;
    while (!in.eof())
    {
        in>>str1>>str2>>k;
        auto nums1 = getArray(str1);
        auto nums2 = getArray(str2);
        print(Solution().maxNumber(nums1,nums2,k));
    }
    
}