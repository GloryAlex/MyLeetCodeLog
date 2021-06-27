#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=909 lang=cpp
 *
 * [909] 蛇梯棋
 */

// @lc code=start
class Solution {
   public:
    int snakesAndLadders(vector<vector<int>>& board) {
        // 棋盘尺寸
        int n = board.size();
        // 摊平棋盘
        bool needReverse = false;
        unordered_map<int,int> destinationOf;
        for(int row=n-1;row>=0;row--){
            if(needReverse)reverse(board[row].begin(),board[row].end());
            for(int col=0;col<n;col++){
                if(board[row][col]>=0){
                    int curPosition = (n-row-1)*n+col+1;
                    destinationOf[curPosition]=board[row][col];
                }
            }
            needReverse = !needReverse;
        }
        //广度优先搜索
        vector<int> hasVisit = vector<int>(n*n+1);
        queue<int> blockQueue;
        blockQueue.push(1);
        for (int steps = 0; !blockQueue.empty(); steps++) {
            int size = blockQueue.size();
            while (size--) {
                int curBlock=blockQueue.front();
                blockQueue.pop();
                if(curBlock==n*n)return steps;
                for(int i=curBlock+1,end=min(curBlock+6,n*n);i<=end;i++){
                    int next = destinationOf.count(i)?destinationOf[i]:i;
                    if(!hasVisit[next]){
                        blockQueue.push(next);
                        hasVisit[next]=true;
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = getMatrix(str);
        print(Solution().snakesAndLadders(arr));
    }
}