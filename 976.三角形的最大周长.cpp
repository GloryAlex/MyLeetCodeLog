#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& a) {
        const int length = a.size();
        if(length<3)return 0;
        sort(a.begin(),a.end(),[&](const int &a,const int &b){return a>b;});

        for(int i=0;i<length-2;i++){
            if(a[i]<a[i+1]+a[i+2])
                return a[i]+a[i+1]+a[i+2];
        }
        return 0;
    }
};

int main(){
    ifstream in("input");
    while(!in.eof()){
        string str;
        in >> str;
        auto arr = getArray(str);
        cout<<Solution().largestPerimeter(arr)<<endl;
    }
}