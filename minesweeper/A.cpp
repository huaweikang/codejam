#include <iostream>

using namespace std;

bool judge(int pos, int start, int end){
	if(pos >= start && pos < end)
		return true;
	return false;
}
bool judgeZero(char map[400][400], int x, int y, int n){
	for(int i = x-1; i <= x+1; i++)
		if(judge(i, 0, n)){
				for(int j = y-1; j <= y+1; j++)
					if(judge(j, 0, n) && map[i][j] == '*')
						return false;
		}	
	
	return true;
}

int dfs(char map[400][400], int x, int y, int n){
	int ret = 0;
	map[x][y] = '$';	
	//cornor
	for(int i = x-1; i <= x+1; i++){
		if(judge(i, 0, n)){
			for(int j = y-1; j <= y+1; j++)
				if(judge(j, 0, n)){
					if(map[i][j] == '.'){
						ret++;
						map[i][j] = '$';
					}
					else if(map[i][j] == '0'){
						ret++;
						ret += dfs(map, i, j, n);
					}
				}	
		}
	}

	return ret;
}
int main(){
	char map[400][400];
	int T;
	cin >> T;
	int t = 0;
	while(t++ < T){
		int n;
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> map[i];
		int sum = n*n;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++){
				if(map[i][j] == '*')
					sum--;
				else if(judgeZero(map, i, j, n) == true)
					map[i][j] = '0';
			}
		//for test
		/*cout << "for test" << endl;
		cout << "sum is " << sum << endl;
		for(int i = 0; i < n; i++)
			cout << map[i] << endl;
		cout << "for test" << endl;*/

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				if(map[i][j] == '0')
					sum -= dfs(map, i, j, n);
		}
		cout << "Case #" << t << ": " << sum << endl;
	}
	return 0;
}
