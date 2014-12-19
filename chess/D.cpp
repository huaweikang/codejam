#include <iostream>
#include <cstring>

using namespace std;

char matrix[100][100];

int king(int x, int y){
	int ret = 0;
	for(int i = -1; i <= 1; i++){
		for(int j = -1; j <= 1; j++)
			if(matrix[x+i][y+j] != '.')
				ret++;
	}	
	ret--;
	return ret;
}

int pawn(int x, int y){
	int ret = 0;
	if(matrix[x+1][y+1] != '.')
		ret++;

	//cout << "ret is " << ret << endl;
	return ret;
}

int queen(int x, int y){
	int ret = 0;
	//up
	for(int i = 0; i < x; i++)
		if(matrix[i][y] != '.'){
			ret++;
			break;
		}
	//down
	for(int i = x+1; i <= 10; i++)
		if(matrix[i][y] != '.'){
			ret++;
			break;
		}
	//left
	for(int i = 0; i < y; i++)
		if(matrix[x][i] != '.'){
			ret++;
			break;
		}
	//right
	for(int i = 0; i < y; i++)
		if(matrix[x][i] != '.'){
			ret++;
			break;
		}
	//up-left
	for(int i = x-1, j = y-1; i > 0 && j > 0; i--, j--)
		if(matrix[i][j] != '.'){
			ret++;
			break;
		}
	//down-right
	for(int i = x+1, j = y+1; i < 10 && j < 10; i++, j++)
		if(matrix[i][j] != '.'){
			ret++;
			break;
		}
	//up-right
	for(int i = x-1, j = y+1; i > 0 && j < 10; i--, j++)
		if(matrix[i][j] != '.'){
			ret++;
			break;
		}
	//down-left
	for(int i = x+1, j = y-1; i < 10 && j > 0; i++, j--)
		if(matrix[i][j] != '.'){
			ret++;
			break;
		}
			
	return ret;
}
int main(){
	int T;
	cin >> T;
	int k = 0;
	while(k++ < T){
		int n;
		cin >> n;
		memset(matrix, '.', sizeof(matrix));
		for(int i = 0; i < n; i++){
			string str;
			cin >> str;
			//cout << str << endl;
			matrix[str[1] - '0'][str[0] - 'A' + 1] = str[3];
		}

		/*for(int i = 1; i <= 8; i++){
			for(int j = 1; j <= 8; j++){
				cout << matrix[i][j] << ' ';
			}
			cout << endl;
		}*/
		int sum = 0;
		for(int i = 1; i <= 8; i++){
			for(int j = 1; j <= 8; j++){
				if(matrix[i][j] != '.'){
				switch (matrix[i][j]){
					case 'K': sum += king(i, j); break;
					case 'P': sum += pawn(i, j); break;
					case 'Q': sum += queen(i, j); break;
				}
		//			cout << matrix[i][j] <<  " sum is "  << sum << endl;
				}
			}
		}

		cout << "Case #" << k << ": " << sum << endl;
	}
	return 0;
}
