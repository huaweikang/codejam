#include <fstream>
#include <iostream>
#define	MAXN	1010

using namespace std;

int main(){
	int t;
	cin >> t;
	int k = 0;
	int badNum = 0;
	while(k++ < t){
		cout << "Case #" << k << ": ";
		int n;
		cin >> n;
		int count = 0;
		for(int i = 0; i < n; i++){
			int tmp;
			cin >> tmp;
			if(tmp <= i)
				count++;
		}	
		if(count < (472 + 500) / 2){
			cout << "BAD" << endl;
			badNum++;
		}
		else
			cout << "GOOD" << endl;
	}
	//cout << "badNum is " << badNum << endl;
}
