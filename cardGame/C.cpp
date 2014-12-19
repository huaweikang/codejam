#include <iostream>
#include <stack>


using namespace std;


int main(){
	int t;
	cin >> t;
	int x = 0;
	while(x++ < t){
		cout << "Case #" << x << ": ";
		int n, k;
		cin >> n >> k;
		stack<int> s;
		for(int i = 0; i < n; i++){
			int tmp;
			cin >> tmp;
			if(s.size() < 2 || s.top() + k == tmp)
				s.push(tmp);
			else{
				while(s.size() >= 3){
					int c = s.top();
					s.pop();
					int b = s.top();
					s.pop();
					int a = s.top();
					if(c - b == k && b - a == k)
						s.pop();
					else{
						s.push(b);
						s.push(c);
						break;
					}
				}
				s.push(tmp);
			}
		}
		while(s.size() >= 3){
				int c = s.top();
				s.pop();
				int b = s.top();
				s.pop();
				int a = s.top();
				if(c - b == k && b - a == k)
					s.pop();
				else{
					s.push(b);
					s.push(c);
					break;
				}
		}
		cout << s.size() << endl;	
	}
	return 0;
}
