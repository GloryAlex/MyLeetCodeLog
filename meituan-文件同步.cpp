//小团觉得每天把自己5斤重的游戏本在家和公司之间来回背的这一行为效率过于低下。于是他决定将自己的一台老爷机放在公司。经过时间的推移，小团意识到同步不同机器上同一份文件的重要性。为了使多台电脑上文件的版本一致，小团使用了一个版本管理软件进行同步。该软件会比较文件之间的差别并汇报冲突，所有冲突都被解决才能完成同步。比如在上一次同步之后，小团将A机器上的文件f修改成了版本f1，并在f1没有同步到B机器上时将 B机器上的文件f修改成了版本f2，则版本管理软件会检测到这一冲突并汇报给小团。否则版本管理软件会直接使用新版的文件覆盖另一台机器上的旧版文件，此时不会汇报冲突。
//
//在上一次同步之后，小团修改了他的游戏本上的许多文件和老爷机上的许多文件。现在给出这些被修改的文件的编号，请你求出版本管理软件会汇报多少个文件的冲突。
//
//
//
//输入描述
//第一行有三个正整数，n(1<=n<=1000000000),m1(1<=m1<=30000),m2(1<=m2<=30000)。代表文件总数，游戏本上的文件被修改了多少次，以及老爷机上的文件被修改了多少次。文件编号为1到n。小团的每一次修改都会影响到编号属于一个连续区间中的所有文件。
//
//第二行和第三行中各有m1个正整数，代表游戏本上每次修改被影响到的文件范围。第二行中的m1个数代表m1次修改中的左端点，第三行中的m1个数代表m1次修改的右端点。
//
//第四行和第五行中各有m2个正整数，代表老爷机上每次修改被影响到的文件范围。第二行中的m2个数代表m2次修改中的左端点，第三行中的m2个数代表m2次修改的右端点。
//
//输出描述
//输出小团的版本管理软件会汇报多少个冲突。即有多少个文件在老爷机和游戏本上都被修改过。
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;

int main(void) {
	int n,m1,m2;
	cin>>n>>m1>>m2;
	vector<pair<int,int>> laptop(m1,{0,0});
	vector<pair<int,int>> desktop(m2,{0,0});
	
	for(auto& i:laptop)cin>>i.first;
	for(auto& i:laptop)cin>>i.second;
	for(auto& i:desktop)cin>>i.first;
	for(auto& i:desktop)cin>>i.second;
	
	unordered_set<int> lap;
	for(auto &i:laptop){
		for(int j=i.first;j<=i.second;j++)lap.insert(j);
	}
	
	int total=0;
	for(auto &i:desktop){
		for(int j=i.first;j<=i.second;j++){
			if(lap.count(j))total++;
		}
	}
	cout<<total<<endl;
	return 0;
}