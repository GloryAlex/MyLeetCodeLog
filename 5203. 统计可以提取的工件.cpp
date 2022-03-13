#include "lib/leetcode.h"
using namespace std;

class Solution {
    struct leetCodePairHash
{
public:
    template <typename T, typename U>
    size_t operator()(const pair<T, U> &x) const
    {
        return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
    }
};
   public:
    int digArtifacts(int n, vector<vector<int>>& artifacts,
                     vector<vector<int>>& dig) {
                         int count = 0;
                         unordered_map<pair<int,int>,int,leetCodePairHash> dict;

                        for(const auto& a:artifacts){
                            int r1=a[0],c1=a[1],r2=a[2],c2=a[3];
                            for(int i=r1;i<=r2;i++){
                                for(int j=c1;j<=c2;j++){
                                    dict[{i,j}]=count;
                                }
                            }
                            count++;
                        }

                        for(const auto& i:dig){
                            int r=i[0],c=i[1];
                            dict.erase({r,c});
                        }

                        unordered_set<int> nums;
                        for(const auto[_,id]:dict){
                            nums.insert(id);
                        }
                        return count-nums.size();
                     }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        int n;
        json j, k;
        in >> n >> ws >> j >> ws >> k >> ws;
        auto art = j.get<vector<vector<int>>>();
        auto dig = k.get<vector<vector<int>>>();
        print(Solution().digArtifacts(n, art, dig));
    }
}