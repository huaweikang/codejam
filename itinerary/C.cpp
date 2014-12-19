#include <iostream>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

bool flag[10010];
struct Ticket{
	string from;
	string to;
};

int main(){
	int T;
	cin >> T;
	int k = 0;
	while(k++ < T){
		int n;
		cin >> n;
		memset(flag, true, sizeof(flag));
		vector<Ticket> vec;
		map<string, int> m;
		for(int i = 0;i < n; i++){
			string a, b;
			cin >> a >> b;
			Ticket t;
			t.from = a;
			t.to = b;
			vec.push_back(t);
			m[a] = i;
		}
		int start = -1;
		for(int i = 0; i < n; i++){
			if(m.find(vec[i].to) != m.end())
				flag[m[vec[i].to]] = false;
		}
		for(int i = 0; i < n; i++)
			if(flag[i] == true){
				start = i;
				break;
			}
		if(start == -1){
			cout << "bad" << endl;
			break;
		}

		cout << "Case #" << k << ":";
		string str = vec[start].from;
		while(m.find(str) != m.end()){
			int num = m[str];
			cout << ' ' << vec[num].from << '-' << vec[num].to;
			str = vec[num].to;
		}

		cout << endl;
	}	

	return 0;
}
