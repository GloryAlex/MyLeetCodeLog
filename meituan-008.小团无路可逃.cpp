#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> getDest(const vector<vector<int>>& graph, int source) {
    int n = graph.size();
    queue<int> q;
    vector<int> hasVisit(n), dest(n);
    q.push(source);
    hasVisit[source] = true;
    for (int step = 0; !q.empty(); step++) {
        int size = q.size();
        while (size--) {
            int cur = q.front();
            q.pop();
            dest[cur] = step;
            for (int next : graph[cur]) {
                if (!hasVisit[next]) {
                    q.push(next);
                    hasVisit[next] = true;
                }
            }
        }
    }
    return dest;
}
int main(int argc, char* argv[]) {
    int n, xPos, yPos;
    cin >> n >> xPos >> yPos;
    xPos--;
    yPos--;
    vector<vector<int>> graph(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
    auto destX = getDest(graph, xPos);
    auto destY = getDest(graph, yPos);
    int res    = 0;
    for (int i = 0; i < n; i++) {
        if (destX[i] > destY[i]) {
            res = max(res, destX[i]);
        }
    }
    cout << res << endl;
}