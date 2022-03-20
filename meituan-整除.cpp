//有一个篮子里装了n个球，球被编号为1到n，且每个球上都写了一个整数。
//
//现在小团想选出一些球。使得这些球满足以下条件：
//
//1. 球上所写的数之和可以被k1整除
//
//2. 球上所写的数之和不能被k2整除
//
//3. 在满足前两个条件的前提下，球上所写的数之和要尽可能的大
//
//小团还想知道在满足这些条件的情况下有多少种不同的选择方法。
//
//两种选择方法相同当且仅当它们选择的球的编号完全相同。
//
//
//
//输入描述
//第一行有三个正整数n, k1 , k2 (1<=n<=100000,1<=k1 , k2<=10)，代表球的数量和小团选择的两个参数。
//
//第二行有 n 个整数，分别代表每个球上写的数。这些数的绝对值不超过1000。
//
//数字间两两有空格隔开。
//
//输出描述
//输出两个数，空格隔开，分别代表满足小团给出的三个条件的方案中球上所写的数之和最大可以有多大，以及满足三个条件的方案的数量。
//
//因为方案数可能非常多，请输出其除以998244353所得的余数。
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

const int mod=998244353;

int need,cannot;
vector<int> arr;

int maxSum=INT_MIN;
pair<int,int> dfs(int i,int sum){
	int total=0;
	if(i==arr.size()){
		if(sum>=maxSum && sum%need==0 && sum%cannot){
			maxSum=sum;
			return {1,maxSum};
		}
		return {0,maxSum};
	}
	if(arr[i]<0&&sum<maxSum)return {0,maxSum};
	
	auto l = dfs(i+1,sum);
	auto r = dfs(i+1,sum+arr[i]);
	return {(l.second==maxSum?l.first:0)%mod+(r.second==maxSum?r.first:0)%mod,maxSum};
}

int main(void) {
	int k;
	cin>>k>>need>>cannot;
	arr = vector<int>(k);
	for(auto& i:arr)cin>>i;
	sort(arr.rbegin(),arr.rend());
	
	auto total = dfs(0,0);
	cout<<maxSum<<' '<<total.first<<endl;
	return 0;
}