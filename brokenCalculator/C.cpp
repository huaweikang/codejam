#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;


int f[1000005];

void dfs(int f[], int num[], int x, int sum){
	if(sum > x)
		return;
	for(int i = 0; i < 10; i++){
		if(num[i] == 1 && sum * 10 + i <= x){
			f[sum*10 + i] = f[sum] + 1;	
			//cout << "test: " << sum*10 + i << " " << f[sum*10 + i] << endl;
			dfs(f, num, x, sum*10 + i);
		}	
	}
}

int main(){
	int T;
	int t = 0;
	cin >> T;
	int num[11];
	while(t++ < T){
		int x;
		for(int i = 0; i < 10; i++){
			cin >> num[i];
			if(num[i] == 1)
				f[i] = 1;
		}
		cin >> x;
		for(int i = 0; i <= x; i++)
			f[i] = INT_MAX;
		for(int i = 0; i < 10; i++)
			if(num[i] == 1)
				f[i] = 1;
		for(int i = 1; i < 10; i++)
			if(f[i] == 1)
				dfs(f, num, x, i);

	/*	//for test
		cout << "for test" << endl;
		for(int i = 0; i < 10; i++)
			cout << num[i] << " ";
		cout << endl;

		for(int i = 0; i <= x; i++){
			cout << f[i] << " ";
		}
		cout << endl;
		cout << "for test" << endl;
*/
		for(int i = 2; i <= x; i++){
			int tmp = sqrt(i);
			//cout << "tmp is " << tmp << endl;
			for(int j = 1; j <= tmp; j++){
				if(i % j == 0 && f[j] != INT_MAX && f[i/j] != INT_MAX)
					f[i] = min(f[i], f[j] + f[i/j] + 1);
			}
		}

		if(f[x] == INT_MAX)
			cout << "Case #" << t << ": Impossible" << endl;
		//else if(x >= 0 && x <= 9)
		//	cout << "Case #" << t << ": " << 1 << endl;
		else
			cout << "Case #" << t << ": " << f[x] + 1 << endl;
	}
	return 0;
}
