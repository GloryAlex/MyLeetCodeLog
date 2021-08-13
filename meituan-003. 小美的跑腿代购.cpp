#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
vector<int> maxN(vector<int>& arr, int n) {
    auto q = priority_queue<int, vector<int>,
        function<bool(int, int)>>([&](int i, int j) {return arr[i] != arr[j] ? arr[i] > arr[j] : i < j;});
    vector<int> result;
    for (int i = 0;i < arr.size();i++) {
        q.push(i);
        if (q.size() > n)q.pop();
    }
    while (!q.empty()) {
        result.push_back(1 + q.top());
        q.pop();
    }
    sort(result.begin(), result.end());
    return result;
}
int main() {
    int maxCapaticity, totalItems;
    vector<int> prices;
    cin >> totalItems >> maxCapaticity;
    for (int i = 0;i < totalItems;i++) {
        int base, weight;
        cin >> base >> weight;
        prices.emplace_back(base + weight * 2);
    }
    for (int i : maxN(prices, maxCapaticity))cout << i << ' ';
}