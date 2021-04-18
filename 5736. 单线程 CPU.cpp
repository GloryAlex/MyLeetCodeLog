#include "LeetCode.h"
using namespace std;

class Solution
{
    struct Task
    {
        int cost;
        int index;
        const bool operator<(const Task &b) const
        {
            return cost == b.cost ? index > b.index : cost > b.cost;
        }
    };

public:
    vector<int> getOrder(vector<vector<int>> &tasks)
    {
        priority_queue<Task> enQueue, processQueue;
        for (int i = 0; i < tasks.size(); i++)
        {
            enQueue.push(Task{tasks[i][0], i});
        }

        long long totalTime = 0;
        vector<int> taskOrder;
        while (!enQueue.empty() || !processQueue.empty())
        {
            if (!processQueue.empty())
            {
                auto curTask = processQueue.top();
                processQueue.pop();
                taskOrder.push_back(curTask.index);
                totalTime += curTask.cost;
            }
            if (!enQueue.empty())
            {
                //什么时候应该执行这一句？
                if (processQueue.empty())
                    totalTime = max(totalTime,(long long) enQueue.top().cost);

                while (!enQueue.empty() && enQueue.top().cost <= totalTime)
                {
                    int index = enQueue.top().index;
                    enQueue.pop();
                    processQueue.push({tasks[index][1], index});
                }
            }
        }
        return taskOrder;
    }
};

int main()
{
    ifstream in("input");
    while (!in.eof())
    {
        string str;
        in >> str;
        auto arr = getMatrix(str);
        print(Solution().getOrder(arr));
    }
}