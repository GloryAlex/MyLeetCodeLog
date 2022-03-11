#include "lib/leetcode.h"
using namespace std;

class Solution {
   public:
    int countHighestScoreNodes(vector<int>& parents) {
        // 构建树
        auto children = vector<pair<int, int>>(parents.size(), {-1, -1});
        auto isNull = [](int node) { return node == -1; };
        for (int i = 0; i < parents.size(); i++) {
            int parent = parents[i];
            if (!isNull(parent)) {
                if (isNull(children[parent].first))
                    children[parent].first = i;
                else
                    children[parent].second = i;
            }
        }
        // 求得每个子树的大小
        auto childrenSize = vector<int>(parents.size());
        function<int(int)> dfs;
        dfs = [&](int root) {
            if (isNull(root))
                return 0;
            else
                return childrenSize[root] = dfs(children[root].first) +
                                            dfs(children[root].second) + 1;
        };

        dfs(0);
        // 计算答案
        auto getRemoveScore = [&](int root) {
            long long cur = root != 0 ? childrenSize[0] - childrenSize[root] : 1;
            if (!isNull(children[root].first))
                cur *= childrenSize[children[root].first];
            if (!isNull(children[root].second))
                cur *= childrenSize[children[root].second];
            return cur;
        };
        long long maxScore = 0;
        int res = 0;
        for (int i = 0; i < parents.size(); i++) {
            auto score = getRemoveScore(i);
            if (maxScore == score) {
                res++;
            } else if (score > maxScore) {
                maxScore = score;
                res = 1;
            }
        }

        return res;
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto arr = j.get<vector<int>>();
        print(Solution().countHighestScoreNodes(arr));
    }
}