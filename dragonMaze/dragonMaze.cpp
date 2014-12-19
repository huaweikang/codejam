#include <fstream>
#include <vector>
#include <iostream>

#define	MAXN	100

using namespace std;

struct node{
	int val;
	int sum;
}matrix[MAXN][MAXN];

int main(){
	ifstream in("D-large-practice.in");
	ofstream out("output");
	int t;
	in >> t;
	int k = 0;
	while(k++ < t){
		out << "Case #" << k << ":";

		int n, m;
		in >> n >> m;
		int enx, eny, exx, exy;
		in >> enx >> eny >> exx >> exy;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++){
				in >> matrix[i][j].val;
				matrix[i][j].sum = 0;
			}
		matrix[enx][eny].sum = matrix[enx][eny].val;
		matrix[enx][eny].val = -1;
		vector<pair<int, int> > pos[2];
		pos[1].push_back(make_pair(enx, eny));
		int cur = 0, pre = 1;
		bool flag = false;
		while(pos[pre].size() != 0 && flag == false){
			cur = !cur;
			pre = !pre;
			pos[pre].clear();
			for(int i = 0; i < pos[cur].size(); i++){
				int x = pos[cur][i].first;
				int y = pos[cur][i].second;
				if(x > 0 && matrix[x-1][y].val != -1 && matrix[x-1][y].val + matrix[x][y].sum > matrix[x-1][y].sum){
					pos[pre].push_back(make_pair(x-1, y));
					matrix[x-1][y].sum = matrix[x-1][y].val + matrix[x][y].sum;
					if(x-1 == exx && y == exy)
						flag = true;
				}
				if(x+1 < n && matrix[x+1][y].val != -1 && matrix[x+1][y].val + matrix[x][y].sum > matrix[x+1][y].sum){
					pos[pre].push_back(make_pair(x+1, y));
					matrix[x+1][y].sum = matrix[x+1][y].val + matrix[x][y].sum;
					if(x+1 == exx && y == exy)
						flag = true;
				}
				if(y > 0 && matrix[x][y-1].val != -1 && matrix[x][y-1].val + matrix[x][y].sum > matrix[x][y-1].sum){
					pos[pre].push_back(make_pair(x, y-1));
					matrix[x][y-1].sum = matrix[x][y-1].val + matrix[x][y].sum;
					if(x == exx && y-1 == exy)
						flag = true;
				}
				if(y+1 < m && matrix[x][y+1].val != -1 && matrix[x][y+1].val + matrix[x][y].sum > matrix[x][y+1].sum){
					pos[pre].push_back(make_pair(x, y+1));
					matrix[x][y+1].sum = matrix[x][y+1].val + matrix[x][y].sum;
					if(x == exx && y+1 == exy)
						flag = true;
				}
			}

			for(int i = 0; i < pos[pre].size(); i++){
				int x = pos[pre][i].first;
				int y = pos[pre][i].second;
				matrix[x][y].val = -1;
			}
		}

		if(flag == false)
			out << " Mission Impossible." << endl;
		else
			out << " " << matrix[exx][exy].sum << endl;
	}
	return 0;
}
