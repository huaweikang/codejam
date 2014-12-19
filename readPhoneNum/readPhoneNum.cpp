#include <string>
#include <fstream>

using namespace std;

string num[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string format[11] = {"zero", "one", "double", "triple", "quadruple", "quintuple", "sextuple", "septuple", "octuple", "nonuple", "decuple"};
void changeToEnglish(ofstream &out, string &str, int start, int len){
	int i = start + 1, count = 1;
	for(; i < start + len; i++){
		if(str[i] != str[i-1]){
			if(count >= 2 && count <= 10){
				out << " " << format[count] << " " << num[str[i-1] - '0'];
			}
			else{
				for(int j = 0; j < count; j++)
					out << " " << num[str[i-1] - '0'];
			}
			count = 1;
		}
		else
			count++;
	}
	if(count >= 2 && count <= 10)
		out << " " << format[count] << " " << num[str[i-1] - '0'];
	else
		for(int j = 0; j < count; j++)
			out << " " << num[str[i-1] - '0'];
}		
int main(){
	ifstream in("A-large-practice.in");
	ofstream out("output");
	int t;
	in >> t;
	int k = 0;
	while(k++ < t){
		string numStr, formatStr;
		in >> numStr >> formatStr;
		out << "Case #" << k << ":";
		int i = 0, len = 0, j = 0;
		for(; i < formatStr.size(); i++){
			if(formatStr[i] != '-')
				len = len * 10 + formatStr[i] - '0';
			else{
				changeToEnglish(out, numStr, j, len);
				j += len;
				len = 0;
			}
		}
		changeToEnglish(out, numStr, j, len);
		out << endl;
	}
	
	in.close();
	out.close();	
	return 0;
}
