#include "lib/leetcode.h"
using namespace std;

class Solution {
public:
	vector<int> countBits(int n) {
		vector<int> bits = {0};
		while(bits.size()<=n){
			int curLength = bits.size();
			for(int j=0;j<curLength && bits.size()<=n;j++){
				bits.push_back(bits[j]+1);
			}
		}
		return bits;
	}
};

int main(int argc, char *argv[]) {
	int n;
	ifstream in("input");
	while(!in.eof()){
		in>>n>>ws;
		print(Solution().countBits(n));
	}
}