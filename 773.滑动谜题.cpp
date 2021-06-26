#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=773 lang=cpp
 *
 * [773] 滑动谜题
 */

// @lc code=start
class Solution {
    class BoardStatus {
        int zeroPosition;
        vector<int> board;

       public:
        BoardStatus(const vector<int>& inputBoard) {
            this->board = inputBoard;
            zeroPosition = find(board.begin(), board.end(), 0) - board.begin();
        }
        BoardStatus(const vector<vector<int>>& inputBoard) {
            for (const auto& i : inputBoard) {
                board.insert(board.end(), i.begin(), i.end());
            }
            zeroPosition = find(board.begin(), board.end(), 0) - board.begin();
        }
        bool operator==(const BoardStatus& b) const {
            return this->board == b.board;
        }
        BoardStatus next(int nextZeroPosition) {
            auto result = BoardStatus(*this);
            swap(result.board[result.zeroPosition],
                 result.board[nextZeroPosition]);
            result.zeroPosition = nextZeroPosition;
            return result;
        }
        const size_t hash() const {
            size_t val = 0;
            for (int i : board) val = val * 10 + i;
            return val;
        }
        int getZeroPosition() { return zeroPosition; }
    };

   public:
    int slidingPuzzle(vector<vector<int>>& board) {
        const auto target = BoardStatus({1, 2, 3, 4, 5, 0});
        auto start = BoardStatus(board);

        auto seen = unordered_set<BoardStatus,
                                  function<const size_t(const BoardStatus&)>>(
            16, [](const BoardStatus& s) { return s.hash(); });
        auto q = queue<BoardStatus>({start});
        seen.insert(start);

        auto pushIfNotVisit = [&](BoardStatus b, int nextPos) {
            auto moveResult = b.next(nextPos);
            if (!seen.count(moveResult)) {
                seen.insert(moveResult);
                q.push(moveResult);
            }
        };

        for (int steps = 0; !q.empty(); steps++) {
            int size = q.size();
            while (size--) {
                auto cur = q.front();
                if (cur == target) return steps;
                q.pop();
                int zeroPos = cur.getZeroPosition();
                // 0可以上下左右移动
                //向左移动
                if (zeroPos != 0 && zeroPos != 3) {
                    pushIfNotVisit(cur, zeroPos - 1);
                }
                //向右移动
                if (zeroPos != 5 && zeroPos != 2) {
                    pushIfNotVisit(cur, zeroPos + 1);
                }
                //上下移动
                pushIfNotVisit(cur, (zeroPos > 2 ? zeroPos - 3 : zeroPos + 3));
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
        print(Solution().slidingPuzzle(arr));
    }
}