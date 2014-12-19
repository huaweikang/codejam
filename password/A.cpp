#include <iostream>
#define	MOD	1000000007
#include <cstring>

using namespace std;

long long int A[110][110];
long long int C[110][100];

long long int cal(long long int n, long long int x);

long long int find(long long int m, long long int n){
	if(A[m][n] != -1)
		return A[m][n];
	long long int res = 1;
	for(long long int i = 1; i < m; i++)
		//res = (((res * cal(n, i)) % MOD) * find(m - i, n - i)) % MOD;
		res = res * cal(n, i) * find(m-i, n-i);
	A[m][n] = res;

	return res;
}

long long int cal(long long int n, long long int x){
	long long int res = 1;
	for(long long int base = n, i = 0; i < x; i++, base--)
		res = res*base;
	for(int i = 1; i <= x; i++)
		res = res/i;

	return res;
}
int main(){
	int t;
	cin >> t;
	int k = 0;
	memset(A, -1, sizeof(A));
	memset(C, -1, sizeof(C));
	//init A array
	for(int i = 1; i <= 100; i++)
		A[1][i] = 1;
	while(k++ < t){
		cout << "Case #" << k << ": ";
		long long int m, n, res;
		cin >> m >> n;
		res = find(m, n);
		cout << res << endl;
	}
}
