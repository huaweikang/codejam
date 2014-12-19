#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int T;
	long long int r, t;
	cin >> T;
	int k = 0;
	while(k++ < T){
		cout << "Case #" << k << ": ";
		cin >> r >> t;
		long long n = sqrt(2*t) - 1;
		long long record = 0;
		while(n*n + (2*r-1)*n <= 2*t){
			if(n*n + (2*r-1)*n <= record)
				break;
			else
				record = n*n + (2*r-1)*n;
		       	n++;
		}
		n--;
		n = n / 2;
		cout << n << endl;	
	}
	return 0;
}
