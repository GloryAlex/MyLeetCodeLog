#include "lib/leetcode.h"
using namespace std;

class Solution {
    vector<int> aliceArrows;
    int maxScore;
    vector<int> maxChoice;
    void dfs(int remain,vector<int> choice,int curScore,int i){
        if(remain==0||i>=aliceArrows.size()){
            if(curScore>maxScore){
                maxScore=curScore;
                maxChoice=choice;
                if(remain>0)maxChoice[0]+=remain;
            }
            return;
        }

        if(remain>aliceArrows[i]){
            choice.push_back(aliceArrows[i]+1);
            dfs(remain-(aliceArrows[i]+1),choice,curScore+i,i+1);
            choice.pop_back();
        }

        choice.push_back(0);
        dfs(remain,choice,curScore,i+1);
    }
   public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        this->aliceArrows=aliceArrows;
        maxScore=0;

        dfs(numArrows,{},0,0);
        while(maxChoice.size()<aliceArrows.size())maxChoice.push_back(0);
        return maxChoice;
    }
};


int main() {
    ifstream in("input");
    while (!in.eof()) {
        int n;
        json j;
        in >> n >> j >> ws;
        auto arr = j.get<vector<int>>();
        print(Solution().maximumBobPoints(n, arr));
    }
}