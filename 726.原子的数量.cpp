#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=726 lang=cpp
 *
 * [726] 原子的数量
 */

// @lc code=start
class Solution {
   public:
    string countOfAtoms(string formula) {
        stack<unordered_map<string, int>> s;
        s.push(unordered_map<string, int>());
        for (int i = 0, length = formula.length(); i < length;) {
            int j = i + 1;
            if (isalpha(formula[i])) {
                while (j < length && islower(formula[j])) j++;
                string atom = string(formula.begin() + i, formula.begin() + j);
                int count = 0;
                while (j < length && isdigit(formula[j])) {
                    count = count * 10 + (formula[j] - '0');
                    j++;
                }
                s.top()[atom] += count ? count : 1;
            } else if (formula[i] == '(') {
                s.push(unordered_map<string, int>());
            } else if (formula[i] == ')') {
                int count = 0;
                while (j < length && isdigit(formula[j])) {
                    count = count * 10 + (formula[j] - '0');
                    j++;
                }
                if (!count) count = 1;
                auto curMolecur = s.top();
                s.pop();
                for (auto& [atom, size] : curMolecur) {
                    s.top()[atom] += size * count;
                }
            }
            i = j;
        }
        vector<string> atoms;
        for (auto& [atom, size] : s.top()) atoms.push_back(atom);
        sort(atoms.begin(),atoms.end());
        
        string result;
        for (auto& atom: atoms) {
            result += atom;
            if (s.top()[atom] > 1) result += to_string(s.top()[atom]);
        }
        return result;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        auto formula = getString(str);
        print(Solution().countOfAtoms(formula));
    }
}