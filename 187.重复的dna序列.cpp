#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

// @lc code=start
class DNA {
   private:
    /*辅助变量*/
    static unordered_map<char, int> getInteger;
    static vector<int> getNucleotide;
    /*实例*/
    int dnaValue;
    int length;

   public:
    /* 构造器 */
    DNA(string dna) {
        dnaValue = 0;
        length = dna.length();
        //计算DNA转四进制值
        int power = 1;
        for (int i = (int)dna.size() - 1; i >= 0; i--) {
            dnaValue += getInteger[dna[i]] * power;
            power *= 4;
        }
    }
    DNA(int value,int length){
        this->dnaValue=value;
        this->length=length;
    }
    /* 转换为字符串 */
    string toString(void) {
        string dna;
        int value = dnaValue;
        while (value) {
            dna += getNucleotide[value % 4];
            value /= 4;
        }
        dna += string(length - (int)dna.size(), 'A');
        reverse(dna.begin(), dna.end());
        return dna;
    }
    int getValue(void) { return dnaValue; }
    void update(char removeFirst, char addLast) {
        dnaValue -= pow(4, length - 1) * getInteger[removeFirst];
        dnaValue *= 4;
        dnaValue += getInteger[addLast];
    }
};
unordered_map<char,int> DNA::getInteger = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
vector<int> DNA::getNucleotide = {'A', 'C', 'G', 'T'};
class Solution {
   public:
    vector<string> findRepeatedDnaSequences(string s) {
        const int length = 10;
        unordered_map<int, int> DNAs;
        DNA dna = s.substr(0, length);
        DNAs[dna.getValue()]++;
        for (int i = 10; i < s.length(); i++) {
            dna.update(s[i - 10], s[i]);
            DNAs[dna.getValue()]++;
        }
        vector<string> repeatDNAs;
        for (const auto& i : DNAs) {
            if (i.second > 1) repeatDNAs.push_back(DNA(i.first,length).toString());
        }
        return repeatDNAs;
    }
};
// @lc code=end

int main() {
    ifstream in("input");
    while (!in.eof()) {
        string str;
        in >> str;
        str = getString(str);
        print(Solution().findRepeatedDnaSequences(str));
    }
}