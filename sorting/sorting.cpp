#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct MyFunction{
	bool operator()(int a, int b) { return a > b; }
}myCmp;
int main(){
	ifstream in("C-large-practice.in");
	ofstream out("output");
	int t;
	in >> t;
	int k = 0;
	while(k++ < t){
		int n;
		in >> n;
		vector<int> vec;
		for(int i = 0; i < n; i++){
			int si;
			in >> si;
			vec.push_back(si);
		}
		vector<int> odd, even;
		for(int i = 0; i < n; i++){
			if(vec[i] & 1)
				odd.push_back(vec[i]);
			else
				even.push_back(vec[i]);
		}
		//sort
		sort(odd.begin(), odd.end());
		sort(even.begin(), even.end(), myCmp);

		out << "Case #" << k << ":";
		for(int i = 0, j = 0, k = 0; i < n; i++){
			if(vec[i] & 1)
				out << " " << odd[j++];
			else
				out << " " << even[k++];
		}

		out << endl;
	}
	return 0;
}
