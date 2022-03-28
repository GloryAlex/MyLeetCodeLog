#include <iostream>
#include <climits>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//001 - 小红杀怪
//vector<vector<int>> dp;
//int foo(int a,int b){
//	return a-b<0?0:a-b;
//}
//int calDamage(int a,int b, int touch,int aoe){
//	if(dp[a][b]!=-1)return dp[a][b];
//	if(a==0&&b==0)return dp[a][b] = 0;
//	
//	int touchA = a>0?calDamage(foo(a,touch), b, touch, aoe):INT_MAX-1;
//	int touchB = b>0?calDamage(a, foo(b,touch), touch, aoe):INT_MAX-1;
//	int aoeAll = calDamage(foo(a,aoe),foo(b,aoe), touch, aoe);
//	return dp[a][b] = min(min(touchA,touchB),aoeAll)+1;
//}

// 002 - 小红标字母
class PinLetter{
	bool isValid(char a,char b){
		return abs(a-b)<=1;
	}
	int score(char a){
		return a-'a'+1;
	}
public:
	int maxScore(string str){
		int pinScore = 0,notPin = 0;
		for(int i=1;i<str.size();i++){
			int nextPin=pinScore;
			if(isValid(str[i], str[i-1])){
				nextPin = max(pinScore,notPin+score(str[i])+score(str[i-1]));
			}
			notPin=max(notPin,pinScore);
			pinScore=nextPin;
		}
		return max(pinScore,notPin);
	}
};

// 003 - 完全二叉树构造
class CompleteBinaryTreeConstruct{
	class OddOrEvenGenerator{
		int val;
	public:
		OddOrEvenGenerator(int n){
			val=n;
		}
		void init(){
			val=0;
		}
		int next(){
			return val = val+2;
		}
	};
public:
	void printlevelOrder(int n){
		vector<vector<int>> levels;
		int oddCount=0,evenCount=0,isOdd=false;
		int i=1,total=n;
		while(total>0){
			levels.push_back(vector<int>(min(i,total)));
			total-=i;
			i*=2;
			
			if(isOdd){
				oddCount+=levels.back().size();
			}else{
				evenCount+=levels.back().size();
			}
			isOdd=!isOdd;
		}
		
		int startLevel=oddCount<evenCount?1:0;
		
		auto e = OddOrEvenGenerator(0);
		auto o = OddOrEvenGenerator(-1);
		
		for(int i=startLevel;i<levels.size();i+=2){
			for(auto &j:levels[i]){
				j=e.next();
			}
		}
		for(int i=startLevel^1;i<levels.size();i+=2){
			for(auto &j:levels[i]){
				j=o.next();
			}
		}
		for(auto i:levels){
			for(int j:i){
				cout<<j<<' ';
			}
		}
		
		return ;
	}
};

// 004 - 小红闯沼泽
class Marsh{
	int m,n;
	vector<vector<int>> grid;
	bool isValid(int x,int y){
		return x>=0&&x<m&&y>=0&&y<n;
	}
	int cost(int x,int y,int nextX,int nextY){
		return (grid[x][y]!=grid[nextX][nextY])+1;
	}
public:
	Marsh(int m,int n){
		this->m=m;
		this->n=n;
		grid=vector<vector<int>>(m,vector<int>(n));
	}
	void initByInput(){
		for(auto& i:grid){
			for(auto& j:i)
				cin>>j;
		}
	}
	int minStep(){
		auto dp = vector<vector<int>>(m,vector<int>(n,INT_MAX-2));
		dp[0][0]=0;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(isValid(i-1, j))dp[i][j]=min(dp[i][j],cost(i,j,i-1,j)+dp[i-1][j]);
				if(isValid(i, j-1))dp[i][j]=min(dp[i][j],cost(i,j,i,j-1)+dp[i][j-1]);
				if(isValid(i, j+1))dp[i][j]=min(dp[i][j],cost(i,j,i,j+1)+dp[i][j+1]);
			}
		}
		return dp.back().back();
	}
};
int main(int argc, char *argv[]) {
	int m,n;
	cin>>m>>n;
	auto mar = Marsh(m, n);
	mar.initByInput();
	
	cout<<mar.minStep()<<endl;
}