#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <fstream>

using namespace std;

int main(){
	//ifstream in("input");
	int t;
	cin >> t;
	int k = 0;
	while(k++ < t){
		cout << "Case #" << k << ":";
		int n;
		cin >> n;
		vector<string> strings;
		for(int i = 0; i < n; i++){
			string str;
			cin >> str;
			strings.push_back(str);
		}
		vector<char> charList;
		vector<vector<int> > charNum(n);
		for(int i = 0, count = 0; i < strings[0].size(); i++){
			if(i+1 < strings[0].size() && strings[0][i] == strings[0][i+1]){
				count++;
			}
			else{
				charList.push_back(strings[0][i]);
				charNum[0].push_back(count);
				count = 0;
			}
		}
		
		bool continueFlag = false;
		for(int i = 1; i < strings.size(); i++){
			int j, listNum, count;
			for(j = 0, listNum = 0, count = 0; j < strings[i].size() && listNum < charList.size(); j++){
				if(strings[i][j] != charList[listNum])
					break;
				else if(j+1 < strings[i].size() && strings[i][j] == strings[i][j+1])
					count++;
				else{
					charNum[i].push_back(count);
					count = 0;
					listNum++;
				}	
			}
			if(j < strings[i].size() || listNum < charList.size()){
				continueFlag = true;
				break;
			}
		}
		if(continueFlag){
			cout << " Fegla Won" << endl;
			continue;
		}
		int ret = 0;
		for(int j = 0; j < charNum[0].size(); j++){
			bool flag = true;
			int num = 0;
			int minSum = INT_MAX;
			while(flag){
				int sum = 0;
				for(int i = 0; i < charNum.size(); i++){
					if(charNum[i][j] > num){
						sum += charNum[i][j] - num;
						flag = false;
					}
					else
						sum += num - charNum[i][j];
				}
				minSum = min(minSum, sum);
				flag = !flag;
				num++;
			}
			ret += minSum;
		}
		cout << " " << ret << endl;
	}
	return 0;
}
