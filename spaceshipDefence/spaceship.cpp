#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#define MAXN 1600
#define MAX	2000000

using namespace std;

void floydWarshall(int matrix[][MAXN], int n){
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(matrix[i][k] + matrix[k][j] < matrix[i][j])
					matrix[i][j] = matrix[i][k] + matrix[k][j];
	}
}
int matrix[MAXN][MAXN];
int main(){
	ifstream in("E-large-practice.in");
	ofstream out("output");
	int t;
	in >> t;
	int k = 0;
	while(k++ < t){
		out << "Case #" << k << ":" << endl;
		map<string, int> colorToNum;
		vector<string> color;
		int n;
		in >> n;
		for(int i = 0, num = 0; i < n; i++){
			string str;
			in >> str;
			if(colorToNum.find(str) == colorToNum.end())
				colorToNum[str] = num++;
			color.push_back(str);
		}	
		for(int i = 0; i < colorToNum.size(); i++)
			for(int j = 0; j < colorToNum.size(); j++)
				matrix[i][j] = MAX;
		for(int i = 0; i < colorToNum.size(); i++)
			matrix[i][i] = 0;
		int m;
		in >> m;
		for(int i = 0; i < m; i++){
			int a, b, t;
			in >> a >> b >> t;
			a--, b--;
			if(colorToNum[color[a]] != colorToNum[color[b]] && t < matrix[colorToNum[color[a]]][colorToNum[color[b]]])
				matrix[colorToNum[color[a]]][colorToNum[color[b]]] = t;	
		}
		floydWarshall(matrix, colorToNum.size());
		int s;
		in >> s;
		while(s--){
			int p, q, t;
			in >> p >> q;
			p--, q--;
			t = matrix[colorToNum[color[p]]][colorToNum[color[q]]];
			if(t < MAX)
				out << t << endl;
			else
				out << -1 << endl;
		}
	}

	in.close();
	out.close();

	return 0;
}
