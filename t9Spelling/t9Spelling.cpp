#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void initMap(vector<pair<char, int> > &m){
	for(char ch = 'a'; ch <= 'z'; ch++){
		if(ch >= 'a' && ch <= 'r')
			m[ch] = make_pair((ch - 'a') / 3 + '2', (ch - 'a') % 3 + 1);
		else if(ch >= 't' && ch <='y')
			m[ch] = make_pair((ch - 't') / 3 + '8', (ch - 't') % 3 + 1);
	}
	m['s'] = make_pair('7', 4);
	m['z'] = make_pair('9', 4);
	m[' '] = make_pair('0', 1);
}
int main(){
	int n;
	string s;
	ifstream in("C-large-practice.in");
	ofstream out("output");
	vector<pair<char, int> >  map;
	map.resize(300);
	initMap(map);
	in >> n;
	getline(in, s);
	int k = 0;
	while(k++ < n){
		string str;
		getline(in, str);
		string res = "";
		for(int i = 0; i < str.size(); i++){
			if(i != 0 && map[str[i]].first == map[str[i-1]].first){
				string tmp(map[str[i]].second, map[str[i]].first);
				res += " " + tmp;
			}
			else{
			       	string tmp(map[str[i]].second, map[str[i]].first);
				res += tmp;
			}
		}
		out <<"Case #" << k << ": " << res << endl; 
	}
	in.close();
	out.close();
	return 0;
}
