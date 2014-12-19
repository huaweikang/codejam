#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

const int num[10] = {0b1111110,			//0
		0b0110000, 0b1101101,		//1, 2	
		0b1111001, 0b0110011,		//3, 4
		0b1011011, 0b1011111,		//5, 6
		0b1110000, 0b1111111, 		//7, 8
		0b1111011};			//9

int main(){
	ifstream in("A-large-practice.in");
	//ifstream in("A-small-practice.in");
	//ifstream in("input");
	ofstream out("output");
	int t;
	in >> t;
	int k = 0;
	while(k++ < t){
		out << "Case #" << k << ":";
		int n;
		in >> n;
		vector<int> state;
		for(int i = 0; i < n; i++){
			string str;
			in >> str;
			int tmp = 0;
			for(int j = 0; j < 7; j++){
				if(str[j] == '1'){
					tmp += (1 << (6 - j));
				}
			}
			state.push_back(tmp);
		}
		//judge if the states about same num is in the same
		if(n > 10){
			int i = 10;
			for(; i < n; i++){
				if(state[i] != state[i%10])
					break;
			}
			if(i < n){
				out << " " << "ERROR!" << endl;
				continue;
			}
		}
		//end judge if the states about same num is in the same
		int ret = -1;
		int start;
		int retNum;
		for(start = 0; start <= 9; start++){
			int isBroken = 0;
			int isNormal = 0;
			int isUnsure = 0;
			int i = 0, count;
			for(count = start; i < n; i++, count = (count + 10 - 1) % 10){
				if((state[i] | num[count]) > num[count])
					break;
				isBroken = (isBroken | (state[i] ^ num[count]));
				isNormal = (isNormal | state[i]);
			}
			if(i < n || (isBroken & isNormal) > 0){
				continue;
			}
			//unambigous
			isUnsure = (((1 << 7) - 1) ^ (isBroken | isNormal));
			if((isUnsure & num[count]) > 0){
				break;
			}
			if(ret == -1)
				ret = (num[count] & isNormal);
			else if(ret != (num[count] & isNormal))
				break;
		}

		//cout << "ret.size() is " << ret.size() << endl;
		if(start <= 9 || ret == -1)
			out << " " << "ERROR!" << endl;
		else{
			out << " ";
			for(int i = 6; i >= 0; i--){
				if(ret & (1 << i)){
					out << 1;
				}
				else
					out << 0;
			}
			out << endl;
		}
	}
	in.close();
	out.close();
	return 0;
}
