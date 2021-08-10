#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution {
    /* 插入排序 */
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
    /* 冒泡排序 */
    void bubbleSort(vector<int>& nums) {
        bool hasSwaped = true;
        while (hasSwaped) {
            hasSwaped = false;
            for (int i = 0; i < (int)nums.size() - 1; i++) {
                if (nums[i] > nums[i + 1]) {
                    swap(nums[i], nums[i + 1]);
                    hasSwaped = true;
                }
            }
        }
    }
    void quickSort(vector<int>& nums, int begin, int end) {
        if (end - begin <= 1) return;
        if (end - begin == 2) {
            if (nums[begin] > nums[begin + 1]) swap(nums[begin], nums[begin + 1]);
            return;
        }
        int left = begin, right = end - 1, middle = begin + (end - begin) / 2;
        int leftVal = nums[left], rightVal = nums[right], middleVal = nums[middle];
        if (leftVal > middleVal) swap(leftVal, middleVal);
        if (leftVal > rightVal) swap(leftVal, rightVal);
        if (middleVal > rightVal) swap(middleVal, rightVal);
        nums[left++]  = leftVal;
        nums[right--] = rightVal;
        nums[middle]  = middleVal;
        swap(nums[left], nums[middle]);
        while (left < right) {
            while (left < right && nums[right] >= middleVal) right--;
            nums[left] = nums[right];
            while (left < right && nums[left] <= middleVal) left++;
            nums[right] = nums[left];
        }
        nums[left] = middleVal;
        quickSort(nums, begin, left);
        quickSort(nums, left, end);
    }

   public:
    vector<int> sortArray(vector<int>& nums) {
        insertSort(nums.begin(), nums.end());
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
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto arr = getArray(str);
        print(Solution().sortArray(arr));
    }
    test(100);
}