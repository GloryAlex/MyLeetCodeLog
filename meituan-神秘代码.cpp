#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;

int divide(int val){
	return (val>>1) + (val&1);
}

string encode(string str){
	string res;
	for(int i=((int)str.size()-1)/2,j=str.size()/2;j<str.size()||i>=0;j++,i--){
		if(i==j){
			res.push_back(str[i]);
		}
		else{
			if(j<str.size())res.push_back(str[i]);
			if(i>=0)res.push_back(str[j]);
		}
	}
	return res;
}

string decode(string str){
	deque<char> q;
	bool pushFront=true;
	for(char i:str){
		if(pushFront)q.push_front(i);
		else q.push_back(i);
		
		pushFront=!pushFront;
	}
	return string(q.begin(),q.end());
}

int main(void) {
	int n;
	int op;
	string str;
	cin>>n>>op>>str;
	
	if(op==1)cout<<encode(str)<<endl;
	else cout<<decode(str)<<endl;
}