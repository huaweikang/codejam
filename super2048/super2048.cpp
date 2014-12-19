#include <fstream>
#include <vector>
#include <iostream>

#define MAXN 20

using namespace std;

int matrix[MAXN][MAXN];

void super2048Change(string str, int n){
	if(str == "right"){
		for(int i = 0; i < n; i++){
			//deal with 0
			int k = n-1;
			for(int j = n-1; j >= 0; j--){
				if(matrix[i][j] == 0)
					continue;
				else
					matrix[i][k--] = matrix[i][j];
			}
			for(; k >= 0; k--)
				matrix[i][k] = 0;

			k = n-1;
			for(int j = n-1; j >=0; j--){
				if(j > 0 && matrix[i][j] == matrix[i][j-1]){
					matrix[i][k--] = 2*matrix[i][j];
					j--;
				}
				else
					matrix[i][k--] = matrix[i][j];
			}
			for(; k >= 0; k--)
				matrix[i][k] = 0;
		}	
	}
	else if(str == "left"){
		for(int i = 0; i < n; i++){
			int k = 0;
			for(int j = 0; j < n; j++){
				if(matrix[i][j] == 0)
					continue;
				else
					matrix[i][k++] = matrix[i][j];
			}
			for(; k < n; k++)
				matrix[i][k] = 0;

			k = 0;
			for(int j = 0; j < n; j++){
				if(j < n-1 && matrix[i][j] == matrix[i][j+1]){
					matrix[i][k++] = 2*matrix[i][j];
					j++;
				}
				else
					matrix[i][k++] = matrix[i][j];
			}
			for(; k < n; k++)
				matrix[i][k] = 0;
		}
	}
	else if(str == "down"){
		for(int j = 0; j < n; j++){
			int k = n-1;
			for(int i = n-1; i >= 0; i--){
				if(matrix[i][j] == 0)
					continue;
				else
					matrix[k--][j] = matrix[i][j];
			}
			for(; k >= 0; k--)
				matrix[k][j] = 0;

			k = n-1;
			for(int i = n-1; i >= 0; i--){
				if(i > 0 && matrix[i][j] == matrix[i-1][j]){
					matrix[k--][j] = 2*matrix[i][j];
					i--;
				}
				else
					matrix[k--][j] = matrix[i][j];
			}
			for(; k >= 0; k--)
				matrix[k][j] = 0;
		}
	}
	else{
		for(int j = 0; j < n; j++){
			int k = 0;
			for(int i = 0; i < n; i++){
				if(matrix[i][j] == 0)
					continue;
				else
					matrix[k++][j] = matrix[i][j];
			}
			for(; k < n; k++)
				matrix[k][j] = 0;
			k = 0;
			for(int i = 0; i < n; i++){
				if(i < n-1 && matrix[i][j] == matrix[i+1][j]){
					matrix[k++][j] = 2*matrix[i][j];
					i++;
				}
				else
					matrix[k++][j] = matrix[i][j];
			}
			for(; k < n; k++)
				matrix[k][j] = 0;
		}
	}
}

int main(){
	ifstream in("B-large.in");
	//ifstream in("input");
	ofstream out("output");
	int t;
	in >> t;
	int k = 0;
	while(k++ < t){
		out << "Case #" << k << ":" << endl;
		int n;
		in >> n;
		string dir;
		in >> dir;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				in >> matrix[i][j];
		super2048Change(dir, n);
		//output
		for(int i = 0; i < n; i++){
			int j;
			for(j = 0; j < n-1; j++)
				out << matrix[i][j] << " ";
			out << matrix[i][j];
			out << endl;
		}
	}
	return 0;
}
