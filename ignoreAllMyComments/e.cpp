#include <stack>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	ifstream in("E-small-practice.in");
	ofstream out("output");
	stringstream ss;
	ss << in.rdbuf();
	string str = ss.str();
	
	stack<int> pre;
	vector<pair<int, int> > delPos;
	int i = 0;
	while(i < str.size() - 1){
		if(str[i] == '/' && str[i+1] == '*'){
			if(pre.size() == 0 || i+2 >= str.size() || str[i+2] != '/'){
				pre.push(i);
				i++;
			}
		}
		else if(str[i] == '*' && str[i+1] == '/'){
			if(pre.size() > 0){
				delPos.push_back(make_pair(pre.top(), i+1));
				pre.pop();
				i++;
			}
		}
		i++;
	}
	sort(delPos.begin(), delPos.end());
	int j, preEnd, delNum;
	for(i = 0, j = 0, preEnd = 0, delNum = 0; i < str.size(); i++){
		while(delNum < delPos.size() && preEnd > delPos[delNum].second)
			delNum++;	
		if(delNum >= delPos.size())
			break;
		if(i < delPos[delNum].first)
			str[j++] = str[i];
		else if(i == delPos[delNum].first){
			i = delPos[delNum].second;
			preEnd = delPos[delNum].second;
			delNum++;
		}
	}
	for(; i < str.size(); i++)
		str[j++] = str[i];

	cout << "j is " << j << endl;
	out << "Case #1:" << endl;
	//str.resize(j);
	out << str.substr(0, j);
	return 0;
}
