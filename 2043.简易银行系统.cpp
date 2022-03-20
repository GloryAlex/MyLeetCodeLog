#include "lib/leetcode.h"
using namespace std;

class Bank{
	vector<long long> balance={(int)1e9};
public:
	Bank(vector<long long>& balance){
		this->balance.insert(this->balance.end(),balance.begin(), balance.end());
	}
	
	bool transfer(int account1,int account2,long long money){
		if(withdraw(account1, money)){
			return deposit(account2, money);
		}
		return false;
	}
	
	bool deposit(int account,long long money){
		balance[account]+=money;
		return true;
	}
	bool withdraw(int account,long long money){
		if(account>=0&&account<balance.size()&&balance[account]>=money){
			balance[account]-=money;
			return true;
		}
		else{
			return false;
		}
	}
};

int main(void) {
	auto in = ifstream("input");
	while(!in.eof()){
		json j,k;
		in>>j>>ws>>k>>ws;
		auto op = j.get<vector<string>>();
		auto args=k.get<vector<vector<long long>>>();
		
		auto b = Bank(args[0]);
		for(int i=1;i<args.size();i++){
			if(op[i]=="transfer")print(b.transfer(args[i][0], args[i][1], args[i][2]));
			else if(op[i]=="deposit")print(b.deposit(args[i][0], args[i][1]));
			else print(b.withdraw(args[i][0], args[i][1]));
		}
	}
}