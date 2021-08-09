#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution {
    /* 选择排序 */
    vector<int> chooseSort(vector<int> nums) {
        auto min = [](vector<int>::iterator begin, vector<int>::iterator end) {
            auto minValue = begin;
            while (begin != end) {
                minValue = *begin < *minValue ? begin : minValue;
                begin++;
            }
            return minValue;
        };
        for (auto i = nums.begin(); i != nums.end() - 1; i++) {
            auto minValue = min(i, nums.end());
            swap(*i, *minValue);
        }
        return nums;
    }
    /* 堆排序 */
    class Heap {
        vector<int> arr = {INT_MIN};
        void adjust(int i) {
            int val   = arr[i];
            int child = i;
            while (i * 2 < arr.size()) {
                child = i * 2;
                if (child + 1 < arr.size() && arr[child] > arr[child + 1]) child++;
                if (arr[child] < val) {
                    arr[i] = arr[child];
                    i      = child;
                } else {
                    break;
                }
            }
            arr[i] = val;
        }

       public:
        Heap(vector<int> a) {
            arr.insert(arr.end(), a.begin(), a.end());
            init();
        }
        void init() {
            for (int i = arr.size() / 2; i >= 0; i--) {
                adjust(i);
            }
        }
        void add(int val) {
            arr.push_back(val);
            if (arr.size() > 2) {
                swap(arr[1], arr.back());
                adjust(1);
            }
        }
        int pop() {
            swap(arr[1], arr.back());
            int val = arr.back();
            arr.pop_back();
            adjust(1);
            return val;
        }
    };
    /* 归并排序 */
    void mergeSort(vector<int>& nums, vector<int>& temp, int begin, int end) {
        if (begin + 1 >= end) return;
        int pivot = (begin + end) / 2;
        mergeSort(nums, temp, begin, pivot);
        mergeSort(nums, temp, pivot, end);

        int i = begin, j = pivot, k = begin;
        while (i != pivot && j != end) {
            if (nums[i] < nums[j])
                temp[k++] = nums[i++];
            else
                temp[k++] = nums[j++];
        }
        while (i != pivot) temp[k++] = nums[i++];
        while (j != end) temp[k++] = nums[j++];
        for (int i = begin; i < end; i++) nums[i] = temp[i];
        return;
    }

   public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size());
        mergeSort(nums, temp, 0, nums.size());
        return nums;
    }
};
// @lc code=end

void test(int n) {
    while (n--) {
        int size = rand() % 10;
        vector<int> test(size);
        for (int& i : test) i = rand() % 20;
        vector<int> temp = test;
        sort(temp.begin(), temp.end());
        if (temp != Solution().sortArray(test)) {
            printf("WA\n");
            print(temp);
            print(test);
            print(Solution().sortArray(test));
            return;
        }
    }
    printf("AC");
}
int main() {
    // ifstream in("input");
    // while (!in.eof()) {
    //     string str;
    //     in >> str;
    //     auto arr = getArray(str);
    //     print(Solution().sortArray(arr));
    // }
    test(100);
}