#include <list>

#include "lib/leetcode.h"
using namespace std;

/*
 * @lc app=leetcode.cn id=432 lang=cpp
 *
 * [432] 全 O(1) 的数据结构
 */

// @lc code=start
class AllOne {
    using CountList = list<pair<unordered_set<string>, int>>;
    CountList lst;
    unordered_map<string, CountList::iterator> dict;

   public:
    AllOne() {}

    void inc(string key) {
        if (dict.count(key)) {
            auto node = dict[key];
            auto nextNode = next(node);
            if (nextNode == lst.end() || nextNode->second != node->second + 1) {
                dict[key] = lst.emplace(nextNode, unordered_set<string>({key}),
                                        node->second + 1);
            } else {
                dict[key] = nextNode;
                nextNode->first.insert(key);
            }
            node->first.erase(key);
            if (node->first.empty()) lst.erase(node);
        } else {
            if (lst.empty() || lst.begin()->second != 1) {
                lst.emplace_front(unordered_set<string>({key}), 1);
            } else {
                lst.begin()->first.insert(key);
            }
            dict[key] = lst.begin();
        }
    }

    void dec(string key) {
        auto node = dict[key];
        if (node->second == 1) {
            dict.erase(key);
        } else {
            auto pre = prev(node);
            if (node == lst.begin() || pre->second < node->second - 1) {
                dict[key] = lst.emplace(node, unordered_set<string>({key}),
                                        node->second - 1);
            } else {
                pre->first.insert(key);
                dict[key] = pre;
            }
        }
        node->first.erase(key);
        if (node->first.empty()) lst.erase(node);
    }

    string getMaxKey() {
        return lst.empty() ? "" : *lst.rbegin()->first.begin();
    }

    string getMinKey() {
        return lst.empty() ? "" : *lst.begin()->first.begin();
    }
};
/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string op, para;
        in >> op >> para >> ws;
        auto ops = getStringArray(op);
        auto temp = getStringMatrix(para);
        vector<string> paras;
        for (auto i : temp) {
            if (i.size())
                paras.push_back(i[0]);
            else
                paras.push_back("");
        }

        auto a = AllOne();
        for (int i = 1; i < ops.size(); i++) {
            if (ops[i] == "inc")
                a.inc(paras[i]);
            else if (ops[i] == "getMaxKey")
                cout << a.getMaxKey() << " ";
            else if (ops[i] == "dec")
                a.dec(paras[i]);
            else if (ops[i] == "getMinKey")
                cout << a.getMinKey() << " ";
        }
        cout << endl;
    }
}
