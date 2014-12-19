#include <fstream>
#include <iostream>
#include <cstring>

#define MAXN 40

using namespace std;

int matrix[MAXN][MAXN];

bool checkRow(int n){
	int len = n * n;
	for(int i = 0; i < len; i++){
		bool flag[len];
		memset(flag, false, sizeof(flag));
		int j;
		for(j = 0; j < len; j++){
			if(matrix[i][j] < 0 || matrix[i][j] >= len || flag[matrix[i][j]] == true)
				break;
			else
				flag[matrix[i][j]] = true;
		}
		if(j < len)
			return false;
	}
	return true;
}
bool checkCol(int n){
	int len = n * n;
	for(int j = 0; j < len; j++){
		bool flag[len];
		memset(flag, false, sizeof(flag));
		int i;
		for(i = 0; i < len; i++){
			if(flag[matrix[i][j]] == true)
				break;
			else
				flag[matrix[i][j]] = true;
		}
		if(i < len)
			return false;
	}
	return true;
}

bool checkSubmetric(int n){
	int len = n * n;
	int i = 0, j = 0;
	int count = 0;
	while(count < len){
		int row = count / n;
		int col = count % n;
		bool flag[len];
		memset(flag, false, sizeof(flag));
		int i;
		for(i = row * n; i < (row + 1) * n; i++){
			int j;
			for(j = col * n; j < (col + 1) * n; j++){
				if(flag[matrix[i][j]] == true)
					break;
				else
					flag[matrix[i][j]] = true;
			}
			if(j < (col + 1) * n)
				break;
		}
		if(i < (row + 1) * n)
			return false;

		count++;
	}

	return true;
}
int main(){
	ifstream in("A-large-practice.in");
	ofstream out("output");
	int t;
	in >> t;
	int k = 0;
	while(k++ < t){
		out << "Case #" << k << ":";
		int n;
		in >> n;
		for(int i = 0; i < n*n; i++)
			for(int j = 0; j < n*n; j++){
				int tmp;
				in >> tmp;
				matrix[i][j] = tmp - 1;

			}

		if(checkRow(n) && checkCol(n) && checkSubmetric(n))
			out << " " << "Yes" << endl;
		else
			out << " " << "No" << endl;
	}
	in.close();
	out.close();
	return 0;
}
