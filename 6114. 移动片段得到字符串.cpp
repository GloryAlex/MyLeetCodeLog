#include "lib/leetcode.h"
using namespace std;

class Solution {
    string erase(const string& input) {
        string temp;
        for (char i : input) {
            if (i != '_') temp.push_back(i);
        }
        return temp;
    }

   public:
    bool canChange(string start, string target) {
        if (erase(start) != erase(target)) return false;
        int i = 0, j = 0;
        for (int i = 0, j = 0; i < start.size() && j < target.size();
             i++, j++) {
            while (i != start.size() && start[i] == '_') i++;
            while (j != target.size() && target[j] == '_') j++;
            if (start[i] == 'L' && i < j)
                return false;
            else if (start[i] == 'R' && i > j)
                return false;
        }
        return true;
    }
};

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j, k;
        in >> j >> k >> ws;
        print(Solution().canChange(j.get<string>(), k.get<string>()));
    }
}