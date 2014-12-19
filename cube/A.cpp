#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//const int len = 1010;
struct Point{
	int num;
	int sum;
};
Point f[1010][1010];

struct MyComparator{
	bool operator() (pair<int, int> &a, pair<int, int> &b) { 
		return f[b.first][b.second].num < f[a.first][a.second].num;
	}
}myCompare;

int main(){
	int T;
	cin >> T;
	int k = 0;
	while(k++ < T){
		int len;
		cin >> len;
		vector<pair<int, int> > vec;
		for(int i = 0; i < len; i++)
			for(int j = 0; j < len; j++){
				cin >> f[i][j].num;
				f[i][j].sum = 1;
				vec.push_back(make_pair(i, j));
			}

		sort(vec.begin(), vec.end(), myCompare);

		
		/*for(vector<pair<int, int> >::iterator it = vec.begin(); it != vec.end(); it++){
			cout << f[it->first][it->second].num << endl;
		}*/

		for(vector<pair<int, int> >::iterator it = vec.begin(); it != vec.end(); it++){
			int x = it->first;
			int y = it->second;
			if(x > 0 && f[x][y].num - 1 == f[x-1][y].num){
				f[x-1][y].sum = f[x][y].sum + 1;
			}
			else if(x < len - 1 && f[x][y].num - 1 == f[x+1][y].num){
				f[x+1][y].sum = f[x][y].sum + 1;
			}
			else if(y > 0 && f[x][y].num - 1 == f[x][y-1].num){
				f[x][y-1].sum = f[x][y].sum + 1;
			}
			else if(y < len - 1 && f[x][y].num - 1 == f[x][y+1].num){
				f[x][y+1].sum = f[x][y].sum + 1;
			}
		}

		int max = 0, r = 0;

		/*for(int i = 0; i < len; i++){
			for(int j = 0; j < len; j++)
				cout << f[i][j].sum << ' ';
			cout << endl;
		}*/
		for(int i = 0; i < len; i++)
			for(int j = 0; j < len; j++){
				if(f[i][j].sum > max){
					max = f[i][j].sum;
					r = f[i][j].num;
				}
				else if(f[i][j].sum == max && f[i][j].num < r)
					r = f[i][j].num;
			}

		cout << "Case #" << k << ": " << r << ' ' << max << endl;
	}
}
