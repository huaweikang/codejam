#include <fstream>
#include <iostream>
#include <vector>

#define MAXN 32

using namespace std;

int piece[MAXN];
int left[MAXN];

void init_piece(int m){
	int amount = m*m;
	for(int i = 30; i >= 0 && amount > 0; i++){
		if(amount > (1 << i)){
			piece[i] += amount / (1 << i);
			amount = amount % (1 << i);
		}
	}
}
int numOfBigTiles(int side[]){
	for(int i = 30; i >= 0; i++){
		if(side
	}
}
int main(){
	ifstream in("input");
	ofstream out("output");
	int t;
	int k = 0;
	while(k++ < t){
		out << "Case #" << k << ":";
		int n, m;
		in >> n >> m;
		int side[32];
		memset(side, 0, sizeof(side));
		for(int i = 0; i < n; i++){
			int s;
			in >> s;
			side[s]++;
		}
		//init left
		memset(left, 0, sizeof(left));
		init_piece(int m);
		
		out << " " << numOfBigTiles(side, m) << endl;		
	}
	return 0;
}
