#include <iostream>
#include <cstring>

using namespace std;

void output(long long int f[110][110], int n, long long int k, int zeroCount){
	if(n == 0)
		return;
	int i;
	for(i = n; i >= 1; i--){
		if(k <= f[n][i])
			break;;
		k -= f[n][i];
	}	
	while(zeroCount < i){
		cout << '(';
		zeroCount++;
	}
	cout << ')';
	zeroCount--;
	output(f, n-1, k, zeroCount);
}
int main(){
	int t;
	cin >> t;
	int x = 0;
	long long int f[110][110];
	memset(f, 0, sizeof(f));

	f[1][1] = 1;
	f[1][0] = 1;
	for(int i = 2; i <= 105; i++){
		f[i][1] = f[i-1][0];
		f[i][0] += f[i][1];
		for(int j = 2; j <= i; j++){
			for(int k = j-1; k < i; k++)
				f[i][j] += f[i-1][k];
			f[i][0] += f[i][j];
		}
	}
	while(x++ < t){
		cout << "Case #" << x << ": ";
		long long int k;
		int n;
		cin >> n >> k;
		if(k < 0)
			cout << "bad idea!" << endl;
		if(k > f[n][0])
			cout << "Doesn't Exist!" << endl;
		else{
			output(f, n, k, 0);
			cout << endl;
		}
	}
	return 0;
}
