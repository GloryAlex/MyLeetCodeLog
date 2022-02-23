#include "lib/leetcode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=1994 lang=cpp
 *
 * [1994] 好子集的数目
 */

// @lc code=start
class Solution {
    const unordered_map<long long, unordered_set<long long>> dict = {
        {1, {}},      {2, {2}},      {3, {3}},   {5, {5}},       {6, {2, 3}},
        {7, {7}},     {10, {2, 5}},  {11, {11}}, {13, {13}},     {14, {2, 7}},
        {15, {3, 5}}, {17, {17}},    {19, {19}}, {21, {3, 7}},   {22, {2, 11}},
        {23, {23}},   {26, {2, 13}}, {29, {29}}, {30, {2, 3, 5}}};
    const long long mod = 1e9 + 7;
    unordered_map<long long, long long> elements;

    long long qpow(long long x, long long n, long long m) {
        long long res = 1;
        while (n) {
            if (n & 1) res = res * x % m;
            x = x * x % m;
            n >>= 1;
        }
        return res;
    }
    bool canInsert(const unordered_set<long long>& factors, long long number) {
        for (long long i : dict.find(number)->second) {
            if (factors.count(i)) return false;
        }
        return true;
    }
    void calculate(unordered_set<long long>& curElemets,
                   unordered_set<long long>& curFactors, long long& result,
                   unordered_map<long long, long long>::iterator it) {
        if (it == elements.end()) {
            // 计算并加到result
            if (curElemets.empty() ||
                (curElemets.size() == 1 && curElemets.count(1)))
                return;
            long long temp = 1;
            for (long long i : curElemets) {
                temp = (temp * elements[i]) % mod;
            }
            result = (result + temp) % mod;
            return;
        }
        long long curNumber = it->first;
        auto next = it;
        next++;
        if (canInsert(curFactors, curNumber)) {
            // 取并集
            curElemets.insert(curNumber);
            for (long long i : dict.find(curNumber)->second) {
                curFactors.insert(i);
            }
            calculate(curElemets, curFactors, result, next);
            // 还原并集
            curElemets.erase(curNumber);
            for (long long i : dict.find(curNumber)->second) {
                curFactors.erase(i);
            }
        }
        calculate(curElemets, curFactors, result, next);
    }

   public:
    int numberOfGoodSubsets(vector<int>& nums) {
        for (long long i : nums) {
            if (dict.count(i)) elements[i]++;
        }
        if (elements.count(1))
            elements[1] = (qpow(2, elements[1], mod) - 1) % mod;
        unordered_set<long long> a, b;
        long long res = 0;
        calculate(a, b, res, elements.begin());
        return res % mod;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto nums = j.get<vector<int>>();
        print(Solution().numberOfGoodSubsets(nums));
    }
}