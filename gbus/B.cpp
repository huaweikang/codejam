#include <iostream>
#include <cstring>

using namespace std;

int f[5010];

int main(){
	int T;
	cin >> T;
	int k = 0;
	while(k++ < T){
		int n;
		cin >> n;
		memset(f, 0, sizeof(f));
		for(int i = 0; i < n; i++){
			int a, b;
			cin >> a >> b;
			f[a]++;
			f[b+1]--;
		}

		for(int i = 1; i <= 5001; i++)
			f[i] += f[i-1];

		cout << "Case #" << k << ":";
		int p;
		cin >> p;
		for(int i = 0; i < p; i++){
			int a;
			cin >> a;
			cout << ' ' << f[a];
		}

		cout << endl;
	}
}
