#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int mask[10][7] = {{1, 1, 1, 1, 1, 1, 0},	//0
	{0, 1, 1, 0, 0, 0, 0}, {1, 1, 0, 1, 1, 0, 1}, // 1, 2
	{1, 1, 1, 1, 0, 0, 1}, {0, 1, 1, 0, 0, 1, 1}, //3, 4
	{1, 0, 1, 1, 0, 1, 1}, {1, 0, 1, 1, 1, 1, 1}, // 5, 6
	{1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1}, //7, 8
	{1, 1, 1, 1, 0, 1, 1}};			//9	
int isBroken[10][7];

int main(){
	//ifstream in("A-small-attempt0.in");
	ifstream in("A-large-practice.in");
	ofstream out("output");
	int t;
	in >> t;
	int k = 0;
	while(k++ < t){
		out << "Case #" << k << ":";
		int n;
		in >> n;
		vector<string> state;
		for(int i = 0; i < n; i++){
			string str;
			in >> str;
			state.push_back(str);
		}

		if(state.size() > 9){
			int i;
			for(i = 10; i < state.size(); i++){
				if(state[i] != state[i%10])
					break;	
			}

			if(i < state.size()){
				out << " " << "ERROR!" << endl;
				continue;
			}
		}

		vector<int> ret;
		memset(isBroken, -1, sizeof(isBroken));	//-1 means state unsure, 0 means breaken, and 1 means OK
		int start;
		for(start = 9; start >= 0; start--){
			int i;
			int num = (start + 10) % 10;
			for(i = 0; i < n; i++, num = (num + 10 - 1) % 10){
				int j;
				for(j = 0; j < 7; j++){
					if(state[i][j] == '1' && isBroken[start][j] == 0)
						break;
					if(state[i][j] == '1' && mask[num][j] == 0)
						break;
					if(state[i][j] == '0' && isBroken[start][j] == 1 && mask[num][j] == 1)
						break;

					if(state[i][j] == '1'){
						isBroken[start][j] = 1; 	//OK
					}
					else{
						if(mask[num][j] == 1)
							isBroken[start][j] = 0;	//breaken
					}
				}
				if(j < 7)
					break;
			}	
			if(i < n)
				continue;

			int j;
			for(j = 0; j < 7; j++){
				if(isBroken[start][j] == -1 && mask[num][j] == 1)
					break;	
			}
			if(j >= 7)
				ret.push_back(start);
			else{
				break;	
			}
		}
		
		//cout << "ret size is " << ret.size() << endl;
	//	cout << "ret[0] + n is " << ret[0] - n << endl;


		if(start >= 0 || ret.size() != 1)
			out << " " << "ERROR!" << endl;
		else{
			out << " ";
			int num = (ret[0] + 10 - n) % 10;
			for(int j = 0; j < 7; j++){
				if(isBroken[ret[0]][j] == 1 && mask[num][j] == 1)
					out << 1;
				else
					out << 0;
			}
			out << endl;
		}
	}
	return 0;
}
