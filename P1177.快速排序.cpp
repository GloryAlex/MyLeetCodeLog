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
            auto j  = i;
            while (j != begin && *(j - 1) > val) {
                *j = *(j - 1);
                j--;
            }
            *j = val;
        }
    }
}
void quickSort(vector<int>& nums, int begin, int end) {
    if (end - begin <= 16) {
        insertSort(nums.begin() + begin, nums.begin() + end);
        return;
    }
    const int len = end - begin;
    int pivot     = nums[begin + rand() % len];
    int i = begin, j = begin, k = end;
    while (i < k) {
        if (nums[i] < pivot)
            swap(nums[i++], nums[j++]);
        else if (nums[i] > pivot)
            swap(nums[i], nums[--k]);
        else
            i++;
    }
    quickSort(nums, begin, j);
    quickSort(nums, k, end);
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> nums(n);
    for (int& i : nums) {
        scanf("%d", &i);
    }
    quickSort(nums, 0, n);
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", nums[i]);
    }
    printf("%d", nums.back());
}