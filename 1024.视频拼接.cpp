#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        return 0;
    }
};

int main(void){
    vector<vector<int>> clips = {
        {0,2},{4,6},{8,10},{1,9},{1,5},{5,9}
    };
    int t = 10;
    cout<< Solution().videoStitching(clips,t);
}