#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=677 lang=cpp
 *
 * [677] 键值映射
 */

// @lc code=start
class MapSum {
    struct Node {
        vector<Node*> next = vector<Node*>(26, nullptr);
        int val            = 0;  //val==0 => no value here
        int getSum() {
            int total = val;
            for (auto& i : next)
                if (i) total += i->getSum();
            return total;
        }
    } Root;

   public:
    /** Initialize your data structure here. */
    MapSum() {}

    void insert(string key, int val) {
        auto node = &Root;
        for (char i : key) {
            if (!node->next[i - 'a']) node->next[i - 'a'] = new Node();
            node = node->next[i - 'a'];
        }
        node->val = val;
    }

    int sum(string prefix) {
        auto node=&Root;
        for(char i:prefix){
            if(!node->next[i-'a'])return 0;
            node=node->next[i-'a'];
        }
        return node->getSum();
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// @lc code=end

int main() {
    MapSum map;
    while (1) {
        string op;
        cin >> op;
        if (op == "insert") {
            string key;
            int val;
            cin >> key >> val;
            map.insert(key, val);
        } else {
            string key;
            cin >> key;
            print(map.sum(key));
        }
    }
}