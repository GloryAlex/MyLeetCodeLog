#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>

using namespace std;

tuple<int, vector<int>, vector<int>> getInput();
vector<int> getMaxWeigthSums(vector<int> weights, vector<int> order);
int main() {
    // 输入：
    //  - 输入第一行包含一个正整数 n ，表示货物的数量。
    //  - 输入第二行包含 n 个正整数，表示 1~n 号货物的重量 w[i] 。
    //  - 输入第三行有 n 个数，表示小美按顺序取出的货物的编号，也就是一个 1~n 的全排列。
    // 输出：
    //  - 输出包含 n 行，每行一个整数，表示每取出一件货物以后，对于重量和最大和最大的一堆货物，其重量和为多少。
    auto [n, weight, order] = getInput();
    for (int i : getMaxWeigthSums(move(weight), move(order))) {
        cout << i << endl;
    }
}
/* Sample Test Case:
Input:
    [3,2,4,4,5]
    [4,3,5,2,1]
Output:
    [9,5,5,3,0]
Explain:
原本的状态是 {{3,2,4,4,5}} ，取出 4 号货物后，得到 {{3,2,4},{5}} ，第一堆货物的和是 9 ，然后取出 3 号货物得到 {{3,2}{5}} ，此时第一堆和第二堆的和都是 5 ，以此类推。
*/
vector<int> getMaxWeigthSums(vector<int> weights, vector<int> order) {
    // TODO: 完成本题
    return weights;
}

tuple<int, vector<int>, vector<int>> getInput() {
    int n;
    cin >> n;
    vector<int> weighets = vector<int>(n);
    vector<int> order = vector<int>(n);
    for (int i = 0;i < n;i++)cin >> weighets[i];
    for (int i = 0;i < n;i++)cin >> order[i];
    return { n, weighets, order };
}