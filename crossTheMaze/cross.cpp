#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#define MAXN 110

using namespace std;
const int N = 0;
const int W = 1;
const int S = 2;
const int E = 3;

const int posX[4] = {-1, 0, 1, 0};
const int posY[4] = {0, -1, 0, 1};
const char dirMap[4] = {'N', 'W', 'S', 'E'};

bool isWall(const char maze[][MAXN], int n, int x, int y){
	if(x < 0 || x >= n || y < 0 || y >= n)
		return true;
	if(maze[x][y] == '#')
		return true;

	return false;
}

int main(){
	ifstream in("D-large-practice.in");
	ofstream out("output");
	char maze[MAXN][MAXN];
	int t;
	in >> t;
	int k = 0;
	while(k++ < t){
		out << "Case #" << k << ":";
		int n;
		in >> n;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				in >> maze[i][j];
		}
		int sx, sy, ex, ey;
		in >> sx >> sy >> ex >> ey;
		sx--, sy--, ex--, ey--;
		int count = 0;
		vector<int> path;
		int preDir;
		if(sx == 0){
			if(sy == 0)
				preDir = E;
			else
				preDir = S;
		}
		else{
			if(sy == 0)
				preDir = N;
			else
				preDir = W;
		}
		while(count <= 10000){
			if(sx == ex && sy == ey)
				break;
			int leftDir = (preDir + 1) % 4;
			if(isWall(maze, n, sx + posX[leftDir], sy + posY[leftDir]) == false){
				path.push_back(leftDir);
				preDir = leftDir;
				sx += posX[leftDir];
				sy += posY[leftDir];
			}	
			else{
				int tmp = 4;
				while(tmp-- > 0 && isWall(maze, n, sx + posX[preDir], sy + posY[preDir])){
						preDir = (preDir + 4 - 1) % 4;
					}
				if(tmp < 0){	//can not get out
					count = 100000;
					break;
				}
				path.push_back(preDir);
				sx += posX[preDir];
				sy += posY[preDir];
			}
			count++;
		}
		if(count > 10000)
			out << " Edison ran out of energy." << endl;
		else{
			out << " " << path.size() << endl;
			for(vector<int>::iterator it = path.begin(); it != path.end(); it++)
				out << dirMap[*it];
			out << endl;
		}	
	}
	in.close();
	out.close();
	return 0;
}
