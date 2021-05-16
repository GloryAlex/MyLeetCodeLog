#include "LeetCode.h"
using namespace std;

class FindSumPairs {
private:
unordered_map<int,int> d1;
unordered_map<int,int> d2;
vector<int> n2;
   public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(int i:nums1)d1[i]++;
        for(int j:nums2)d2[j]++;
        n2=nums2;
    }

    void add(int index, int val) {
        if(!--d2[n2[index]])d2.erase(n2[index]);
        n2[index]+=val;
        d2[n2[index]]++;
    }

    int count(int tot) {
        int total = 0;
        for(auto i:d1){
            if(d2.count(tot-i.first))total+=i.second*(d2[tot-i.first]);
        }
        return total;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str, s2;
        in >> str >> s2;
        auto arr = getArray(str);
        auto arr2 = getArray(s2);
        auto f = FindSumPairs(arr, arr2);
        while (1) {
            cin >> str;
            if (str == "count") {
                int k;
                cin >> k;
                cout << f.count(k);
            } else if (str == "add") {
                int a, b;
                cin >> a >> b;
                f.add(a, b);
            } else
                break;
        }
    }
}