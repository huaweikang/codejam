#include <fstream>
#include <iostream>

using namespace std;

void makeRationNum(ofstream &out, unsigned long long int n){
	int len = -1;
	unsigned long long int tmp = n, p, q;
	while(tmp){
		len++;
		tmp = tmp >> 1;
	}
	p = 1, q = 1;
	len--;
	while(len >= 0){
		if(n & (1 << len)){
			p = p + q;
		}
		else
			q = p + q;
		len--;
	}
	out << " " << p << " " << q;
}
void calculatePos(ofstream &out, unsigned long long int p, unsigned long long int q){
	int len = 0;
	unsigned long long int n = 0;
//	cout << "p is " << p << "q is " << q << endl;
	while(p != 1 || q != 1){
		if(p > q){
			n += (1 << len);
			p = p - q;
		}
		else
			q = q - p;
		len++;
//		cout << "len is " << len << endl;
	}
	n += (1 << len);

	out << " " << n;
}
int main(){
	ifstream in("B-large-practice.in");
	ofstream out("output");
	cout << "size " << sizeof(unsigned long long int) << endl;
	int t;
	in >> t;
	int k = 0;
	while(k++ < t){
		out << "Case #" << k << ":";
		int signal;
		unsigned long long int n, p, q;
		in >> signal;
		if(signal == 1){
			in >> n;
			makeRationNum(out, n);
		}
		else{
			in >> p >> q;
			calculatePos(out, p, q);
		}
		out << endl;
	}
	out << endl;
	calculatePos(out, 64, 1);
	out << endl;
	in.close();
	out.close();
	return 0;
}
