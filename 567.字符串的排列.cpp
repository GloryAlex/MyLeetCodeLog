#include "LeetCode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
  class Dictionary {
    vector<int> dict = vector<int>(26);
    int size = 0;

   public:
   void addAll(string::iterator begin,string::iterator end){
       while(begin!=end){
           add(*begin++);
       }
   }
   void removeAll(string::iterator begin,string::iterator end){
       while(begin!=end){
           remove(*begin++);
       }
   }
   void add(char i){
       i -= 'a';
       if(dict[i]==-1)size--;
       else if(dict[i]==0)size++;

       dict[i]++;
   }
   void remove(char i){
       i -= 'a';
       if(dict[i]==1)size--;
       else if(dict[i]==0)size++;
       
       dict[i]--;
   }
   int empty(){
       return !size;
   }
  };

 public:
  bool checkInclusion(string s1, string s2) {
      int len1=s1.size(),len2=s2.size();
    if (len1 > len2) return false;
    Dictionary dict;
    dict.addAll(s1.begin(),s1.end());
    dict.removeAll(s2.begin(),s2.begin()+len1);
    for(int i=len1;i<len2;i++){
        if(dict.empty())return true;
        dict.remove(s2[i]);
        dict.add(s2[i-len1]);
    }
    return dict.empty();
  }
};
// @lc code=end

int main() {
  ifstream in("input");
  while (!in.eof()) {
    string s1, s2;
    in >> s1 >> s2;
    s1 = getString(s1);
    s2 = getString(s2);
    print(Solution().checkInclusion(s1, s2));
  }
}