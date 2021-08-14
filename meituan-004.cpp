#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n + 1);
    vector<int> b(n + 1, -1);
    for (int i = 1;i < a.size();i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &n);
    while (n--) {
        int op;
        scanf("%d", &op);
        if (--op) {
            int index;
            scanf("%d", &index);
            printf("%d\n", b[index]);
        }
        else {
            int k, x, y;
            scanf("%d%d%d", &k, &x, &y);
            for (int i = 0;i < k && x < a.size() && y < b.size();i++, x++, y++) {
                b[y] = a[x];
            }
        }
    }
}