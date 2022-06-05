#include "lib/leetcode.h"
using namespace std;

class TextEditor {
    int MAX_SHOW = 10;
    deque<char> l, r;

   public:
    TextEditor() {}
    string build() {
        auto it = l.rbegin();
        string res;
        for (int i = 0; i < MAX_SHOW && it != l.rend(); it++, i++) {
            res.push_back(*it);
        }
        reverse(res.begin(), res.end());
        return res;
    }
    void addText(string text) {
        for (char c : text) l.push_back(c);
    }

    int deleteText(int k) {
        int res = min(k, (int)l.size());
        for (int i = 0; i < res; i++) l.pop_back();
        return res;
    }

    string cursorLeft(int k) {
        int realMove = min(k, (int)l.size());
        for (int i = 0; i < realMove; i++) {
            char c = l.back();
            l.pop_back();
            r.push_front(c);
        }
        return build();
    }

    string cursorRight(int k) {
        int move = min(k, (int)r.size());
        for (int i = 0; i < move; i++) {
            char c = r.front();
            r.pop_front();
            l.push_back(c);
        }
        return build();
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */

int main() {
    ifstream in("input");
    while (!in.eof()) {
        json j;
        in >> j >> ws;
        auto ops = j.get<vector<string>>();
        in >> j >> ws;
        auto args = j.get<vector<string>>();
        TextEditor* obj = new TextEditor();
        for (int i = 1; i < ops.size(); i++) {
            auto op = ops[i];
            auto arg = args[i];
            if (op == "addText") {
                obj->addText(arg);
            } else if (op == "deleteText") {
                print(obj->deleteText(stoi(arg)));
            } else if (op == "cursorRight") {
                print(obj->cursorRight(stoi(arg)));
            } else if (op == "cursorLeft") {
                print(obj->cursorRight(stoi(arg)));
            }
        }
    }
}