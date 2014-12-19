#include <iostream>

#define MAXN 110

using namespace std;

char board[MAXN][MAXN];

int dfs(int n, int x, int y, char color){
	board[x][y] = '.';
	int  count = 0;
	if(color == 'B' && y == n-1)
		count++;
	if(color == 'R' && x == n-1)
		count++;
	//right
	if(y < n-1 && board[x][y+1] == color)
		count += dfs(n, x, y+1, color);
	if(x < n-1 && board[x+1][y] == color)
	        count += dfs(n, x+1, y, color);
	if(y > 0 && board[x][y-1] == color)
		count += dfs(n, x, y-1, color);
	if(x > 0 && board[x-1][y] == color)
		count += dfs(n, x-1, y, color);
	if(x < n-1 && y > 0 && board[x+1][y-1] == color)
		count += dfs(n, x+1, y-1, color);
	if(x > 0 && y < n-1 && board[x-1][y+1] == color)
		count += dfs(n, x-1, y+1, color);

	return count;
}

int maxFlow(int n, char color){
	
}
int main(){
	int t;
	cin >> t;
	int k = 0;
	while(k++ < t){
		cout << "Case #" << k << ":";
		int n;
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> board[i];
		int countB = 0, countR = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(board[i][j] == 'B')
					countB++;
				else if(board[i][j] == 'R')
					countR++;

		cout << "countB is "  << countB << endl;
		cout << "countR is "  << countR << endl;

		if(countB - countR > 1 || countR - countB > 1){
			cout << " Impossible" << endl;
			continue;
		}
		//check if Blue connect
		int connectB = 0;
		for(int i = 0; i < n; i++){
			if(board[i][0] == 'B'){
				connectB += dfs(n, i, 0, 'B');
			}
		}
		//
		int connectR = 0;
		for(int i = 0; i < n; i++){
			if(board[0][i] == 'R'){
				connectR += dfs(n, 0, i, 'R');
			}
		}
		
		cout << "connectB is "  << connectB << endl;
		cout << "connectR is "  << connectR << endl;

		if(connectB > 1 || connectR > 1)
			cout << " Impossible" << endl;
		else if((connectB == 1 && connectR == 1) || (connectB == 1 && countB < countR) || (connectR == 1 && countR < countB))
			cout << " Impossible" << endl;
		else if(connectB == 1 && countB >= countR)
			cout << " Blue wins" << endl;
		else if(connectR == 1 && countR >= countB)
			cout << " Red wins" << endl;
		else if(connectR == 0 && connectB== 0)
			cout << " Nobody wins" << endl;
	}
	return 0;
}
