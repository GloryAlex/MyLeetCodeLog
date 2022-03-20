#include <iostream>
#include <vector>
using namespace std;
int main(void) {
//	3
//	5 10 8
//	5 8 7
//	2
//	15 22
//	1 4
	int n=0;
	cin>>n;
	vector<int> price(n);
	vector<int> discountPrice(n);
	for(int &i:price)cin>>i;
	for(int &i:discountPrice)cin>>i;
	int m;
	cin>>m;
	vector<int> limit(m);
	vector<int> promo(m);
	for(int &i:limit)cin>>i;
	for(int& i:promo)cin>>i;
	
	int originTotal=0,discountTotal=0;
	for(int i=0,j=0;i<n;i++){
		originTotal+=price[i];
		discountTotal+=discountPrice[i];
		
		while(j<m&&limit[j]<=originTotal)j++;
		
		int canPromo=0;
		if(j<m&&limit[j]<=originTotal){
			canPromo=promo[j];
		}
		else if(j>0&&limit[j-1]<=originTotal){
			canPromo=promo[j-1];
		}
		
		if(originTotal-canPromo>discountTotal){
			cout<<'Z';
		}else if(originTotal-canPromo<discountTotal){
			cout<<'M';
		}else{
			cout<<'B';
		}
	}
	cout<<endl;
	return 0;
}