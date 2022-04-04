#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 */

// @lc code=start
class NumArray {
    vector<int> segTree;
    int length;

   private:
    int midOf(int l, int r) { return l + (r - l) / 2; }
    int leftChildOf(int father) { return father * 2 + 1; }
    int rightChildOf(int father) { return father * 2 + 2; }
    void updateFather(int father) {
        segTree[father] =
            segTree[leftChildOf(father)] + segTree[rightChildOf(father)];
    }
    void init(int curNode, int left, int right, vector<int>& nums) {
        if (left == right) {
            segTree[curNode] = nums[left];
            return;
        }
        int mid = midOf(left, right);
        init(leftChildOf(curNode), left, mid, nums);
        init(rightChildOf(curNode), mid + 1, right, nums);

        updateFather(curNode);
    }

    void update(int index, int value, int curNode, int left, int right) {
        if (left == right) {
            segTree[curNode] = value;
            return;
        }
        int mid = midOf(left, right);
        if (index <= mid) {
            update(index, value, curNode * 2 + 1, left, mid);
        } else {
            update(index, value, curNode * 2 + 2, mid + 1, right);
        }
        updateFather(curNode);
    }
    int getRangeSum(int numsLeft, int numsRight, int curNode, int left,
                    int right) {
        if (left == numsLeft && right == numsRight) {
            return segTree[curNode];
        }
        int mid = midOf(left, right);
        if (numsRight <= mid) {
            return getRangeSum(numsLeft, numsRight, leftChildOf(curNode), left,
                               mid);
        } else if (numsLeft > mid) {
            return getRangeSum(numsLeft, numsRight, rightChildOf(curNode),
                               mid + 1, right);
        } else {
            return getRangeSum(numsLeft, mid, leftChildOf(curNode), left, mid) +
                   getRangeSum(mid + 1, numsRight, rightChildOf(curNode),
                               mid + 1, right);
        }
    }

   public:
    NumArray(vector<int>& nums)
        : length(nums.size()), segTree(vector<int>(4 * nums.size())) {
        init(0, 0, length - 1, nums);
    }

    void update(int index, int val) { update(index, val, 0, 0, length - 1); }

    int sumRange(int left, int right) {
        return getRangeSum(left, right, 0, 0, length - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end
int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto ops = j.get<vector<string>>();
        in >> j >> ws;
        auto args = j.get<vector<vector<int>>>();
        auto n = NumArray(args[0]);
        for (int i = 1; i < ops.size(); i++) {
            if (ops[i] == "sumRange")
                print(n.sumRange(args[i][0], args[i][1]));
            else
                n.update(args[i][0], args[i][1]);
        }
    }
}
