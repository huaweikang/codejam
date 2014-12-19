#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>

using namespace std;

int main(){
	ifstream in("B-large-practice.in");
	ofstream out("output");
	int n, k;
	k = 0;
	in >> n;
	string s;
	getline(in, s);
	while(k++ < n){
		string str;
		getline(in, str);
		reverse(str.begin(), str.end());
		int i, j;
		for(i = 0, j = 0; i < str.size(); i++){
			if(str[i] == ' '){
				reverse(&(str[j]), &(str[i]));
				j = i+1;
			}
		}
		reverse(&(str[j]), &(str[i]));

		out <<"Case #" << k << ": "<< str << endl;
	}

	in.close();
	out.close();
	return 0;
}
