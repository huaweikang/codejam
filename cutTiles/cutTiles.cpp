#include <fstream>
#include <cstring>
#include <iostream>

#define	MAXN 32

using namespace std;

unsigned long long int pieces[MAXN];

void addOneBigTile(unsigned long long int left[], int start){
	for(int i = 30; i >= start; i--){
		pieces[i] += pieces[i+1] * 4;
		pieces[i+1] = 0;	
	}
	for(int i = start; i >= 0; i--){
		left[i] += pieces[i];
	}
}
void addOneBigTile(unsigned long long int left[], int start, const unsigned int m){
	unsigned long long int tmp = (m >> start);
	left[start] += tmp * tmp;
	for(int i = start - 1; i >= 0; i--){
		if(m & (1 << i)){
			left[i] += (m >> i)*2 - 1;
		}
	}	
}
void init_piece(unsigned int m){
	memset(pieces, 0, sizeof(pieces));
	for(int i = 31; i >= 0; i--){
		if(m & (1 << i)){
			pieces[i] += (m >> i)*2 - 1;
		}
	}
}
int numOfBigTiles(int tiles[], unsigned int m){
	unsigned long long int left[MAXN];
	int ret = 0;
	memset(left, 0, sizeof(left));

	//init_piece(m);

	for(int i = 30; i >= 0; i--){
		left[i] += left[i+1] * 4;
		left[i+1] = 0;
		if(left[i] >= tiles[i])
			left[i] -= tiles[i];
		else{
			while(left[i] < tiles[i]){
				addOneBigTile(left, i, m);
				ret++;
			}
			left[i] -= tiles[i];
		}
	}
	return ret;
}
int main(){
	ifstream in("D-large-practice.in");
	//ifstream in("D-small-practice.in");
	//ifstream in("input");
	ofstream out("output");
	int t;
	in >> t;
	int k = 0;
	while(k++ < t){
		out << "Case #" << k << ":";
		cout << "Case #" << k << ":";
		int n;
		unsigned int m;
		in >> n >> m;
		int tiles[MAXN];
		memset(tiles, 0, sizeof(tiles));
		while(n--){
			int tmp;
			in >> tmp;
			tiles[tmp]++;
		}
		
		out << " " << numOfBigTiles(tiles, m) << endl;
		cout << " " << numOfBigTiles(tiles, m) << endl;
	}
	in.close();
	out.close();
	return 0;
}
