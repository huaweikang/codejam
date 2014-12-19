#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>

#define	MAXN 160
#define MAXL 50

using namespace std;

unsigned long long int outlet[MAXN];
unsigned long long int dev[MAXN];
int outletOneBit[MAXL];
int devOneBit[MAXL];
int minSwitchTime;

void switchBit(int n, int bitPos){
	for(int i = 0; i < n; i++){
		outlet[i] = (outlet[i] ^ (1 << bitPos));
	}
}
bool switchOutlet(vector<int> needSwitch, int start, int &timeOfSwitch, int n);
int main(){
	ifstream in("A-small-practice.in");
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
		memset(outletOneBit, 0, sizeof(outletOneBit));
		for(int i = 0; i < n; i++){
			string str;
			in >> str;
			for(int j = l-1; j >=0; j--){
				if(str[j] == '1'){
					outlet[i] = (outlet[i] | (1 << (l-1-j)));
					outletOneBit[l-1-j]++;
				}
			}
		}
		memset(dev, 0, sizeof(dev));
		memset(devOneBit, 0, sizeof(devOneBit));
		for(int i = 0; i < n; i++){
			string str;
			in >> str;
			for(int j = l-1; j >= 0; j--){
				if(str[j] == '1'){
					dev[i] = (dev[i] | (1 << (l-1-j)));
					devOneBit[l-1-j]++;
				}
			}
		}

		sort(dev, dev+n);

		bool flag = true;
		for(int i = 0; i < l; i++)
			if(outletOneBit[i] != devOneBit[i] && outletOneBit[i] != n - devOneBit[i]){
				flag = false;
				break;
			}
		if(flag == false){
			out << "NOT POSSIBLE" << endl;
			continue;
		}	
		int timeOfSwitch = 0;
		minSwitchTime = l;
		vector<int> needSwitch;
		for(int i = 0; i < l; i++){
			if(outletOneBit[i] == devOneBit[i] && outletOneBit[i] == n - devOneBit[i])
				needSwitch.push_back(i);
			else if(outletOneBit[i] == n - devOneBit[i]){
				timeOfSwitch++;
				switchBit(n, i);
			}
		}
		cout << "timeOfSwitch is " << timeOfSwitch << endl;
		//dfs 
		flag = switchOutlet(needSwitch, 0, timeOfSwitch, n);
		if(flag == false){
			out << "NOT POSSIBLE" << endl;
		}	
		else{
			out << minSwitchTime << endl;
		}
	}
	return 0;
}


bool switchOutlet(vector<int> needSwitch, int start, int &timeOfSwitch, int n){
	if(start == needSwitch.size()){
		//judge
		vector<int> outleftAfterSwitch(outlet, outlet + n);
		sort(outleftAfterSwitch.begin(), outleftAfterSwitch.end());
		int i;
		for(i = 0; i < n; i++)
			if(dev[i] != outleftAfterSwitch[i])
				break;
		if(i < n)
			return false;
		else{
			minSwitchTime = timeOfSwitch;
			return true;
		}
	}
	// not switch
	bool flag = switchOutlet(needSwitch, start+1, timeOfSwitch, n);
	if(timeOfSwitch >= minSwitchTime - 1)
		return flag;
	switchBit(n, start);
	timeOfSwitch++;
	if(switchOutlet(needSwitch, start+1, timeOfSwitch, n))
		return true;
	switchBit(n, start);
	timeOfSwitch--;

	return flag;
}
