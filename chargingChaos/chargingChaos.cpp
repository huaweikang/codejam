#include <fstream>
#include <vector>
#include <cstring>
#include <set>
#include <algorithm>
#include <iostream>

#define	MAXN 200
#define MAXL 50

using namespace std;

unsigned long long int outlet[MAXN];
unsigned long long int dev[MAXN];

/*int countOneBit(unsigned long long int num){
	int ret = 0;
	while(num > 0){
		num = (num - 1) & num;
		ret++;
	}
	return ret;
}*/
const unsigned long long int one = 1;
int countOneBit(unsigned long long int num, int l){
	int ret = 0;
	for(int i = 0; i < l; i++)
		if(num & (one << i))
			ret++;
	return ret;
}
int main(){
	ifstream in("A-large-practice.in");
	//ifstream in("input");
	ofstream out("output");
	int t;
	in >> t;
	int k = 0;
	while(k++ < t){
		out << "Case #" << k << ": ";
		int n, l;
		in >> n >> l;
		memset(outlet, 0, sizeof(outlet));
		for(int i = 0; i < n; i++){
			string str;
			in >> str;
			for(int j = 0; j < l; j++)
				if(str[j] == '1')
					outlet[i] |= one << (l-1-j);
		}
		memset(dev, 0, sizeof(dev));
		for(int i = 0; i < n; i++){
			string str;
			in >> str;
			for(int j = 0; j < l; j++)
				if(str[j] == '1')
					dev[i] |= one << (l-1-j);
		}
		for(int i = 1; i < n; i++){
			if(dev[i] == dev[i-1])
				cout << "unhappy" << endl;
		}
		//filp outlet[0] to dev[i]
		int minChangeBit = l+1;
		for(int i = 0; i < n; i++){
			unsigned long long int mask = outlet[0] ^ dev[i];
			set<unsigned long long int> flow;
			for(int j = 0; j < n; j++)
				flow.insert(outlet[j] ^ mask);
			bool flag = true;
			for(int j = 0; j < n; j++)
				if(flow.find(dev[j]) == flow.end()){
					flag = false;
					break;
				}
			if(flag){
				cout << "countOneBit(mask) " << countOneBit(mask, l) << endl;
				minChangeBit = min(minChangeBit, countOneBit(mask, l));
				//cout << "minChangeBit is " << minChangeBit << endl;
			}
		}

		if(minChangeBit > l)
			out << "NOT POSSIBLE" << endl;
		else
			out << minChangeBit << endl;
	}
}
