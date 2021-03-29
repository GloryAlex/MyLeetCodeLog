#include "LeetCode.h"
using namespace std;

class Solution
{
public:
    vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems)
    {
        vector<vector<int>> groupItems(m, vector<int>());
        for (int i = 0; i < n; i++)
        {
            if (group[i] < 0)
            {
                group[i] = groupItems.size();
                groupItems.push_back({i});
            }
            else
            {
                groupItems[group[i]].push_back(i);
            }
        }

        vector<vector<int>> workRelationship(n, vector<int>());
        vector<vector<int>> groupRelationship(groupItems.size(), vector<int>());

        vector<int> workDegree(n);
        vector<int> groupDegree(groupItems.size());
        for (int curItem = 0; curItem < beforeItems.size(); curItem++)
        {
            for (int beforeItem : beforeItems[curItem])
            {
                if (group[curItem] == group[beforeItem])
                {
                    //在同个组内
                    workRelationship[beforeItem].emplace_back(curItem);
                    workDegree[curItem]++;
                }
                else
                {
                    //在不同的组内
                    int beforeGroup = group[beforeItem], curGroup = group[curItem];
                    groupRelationship[beforeGroup].emplace_back(curGroup);
                    groupDegree[curGroup]++;
                }
            }
        }

        auto range = [&](int begin, int end) {
            vector<int> ret(end - begin);
            for (int i = begin; i < end; i++)
            {
                ret[i] = i;
            }
            return ret;
        };
        auto topSort = [&](vector<int> &degree, vector<int> &items, vector<vector<int>> &graph) {
            vector<int> ret;
            queue<int> q;
            for (int i : items)
            {
                if (degree[i] == 0)
                    q.push(i);
            }
            while (!q.empty())
            {
                int cur = q.front();

                ret.emplace_back(cur);
                q.pop();

                for (auto i : graph[cur])
                {
                    if (!--degree[i])
                        q.push(i);
                }
            }
            return ret.size() == items.size() ? ret : vector<int>{};
        };

        auto id = range(0, groupItems.size());
        auto groupTopSortedResult = topSort(groupDegree, id, groupRelationship);

        vector<int> finalResult;
        for (int i : groupTopSortedResult)
        {
            if (groupItems[i].size())
            {
                if (groupItems[i].size() == 1)
                {
                    finalResult.emplace_back(groupItems[i][0]);
                }
                else
                {
                    auto tempRes = topSort(workDegree, groupItems[i], workRelationship);

                    if (tempRes.empty())
                        return {};
                    finalResult.insert(finalResult.end(), tempRes.begin(), tempRes.end());
                }
            }
        }

        return finalResult;
    }
};

int main()
{
    int m = 5;
    int n = 5;
    vector<int> arr = {2, 0, -1, 3, 0};
    vector<vector<int>> matrix = {{2, 1, 3}, {2, 4}, {}, {}, {}};
    auto res = Solution().sortItems(m, n, arr, matrix);
    print(res);
}