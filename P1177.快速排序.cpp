#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

void insertSort(vector<int>::iterator begin, vector<int>::iterator end) {
    for (auto i = begin + 1; i < end;) {
        while (i < end && *i >= *(i - 1)) i++;
        if (i < end) {
            int val = *i;
            auto j = i;
            while (j != begin && *(j - 1) > val) {
                *j = *(j - 1);
                j--;
            }
            *j = val;
        }
    }
}

void quickSort(vector<int>::iterator begin, vector<int>::iterator end) {
    if (end - begin <= 16) {
        return insertSort(begin, end);
    }
    const int len = end - begin;
    int pivot = *(begin + rand() % len);
    auto i = begin, j = begin, k = end;
    while (i < k) {
        if (*i < pivot)swap(*i++, *j++);
        else if (*i > pivot)swap(*i, *--k);
        else i++;
    }
    quickSort(begin, j);
    quickSort(k, end);
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> nums(n);
    for (int& i : nums) {
        scanf("%d", &i);
    }
    quickSort(nums.begin(),nums.end());
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", nums[i]);
    }
    printf("%d", nums.back());
}