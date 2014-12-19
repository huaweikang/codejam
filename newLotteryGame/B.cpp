#include <iostream>
#include <cstring>

using namespace std;

int getbit(int num, int i){
	return (num >> i) & 1;
}

long long int record[40][2][2][2];

long long int countPairs(int i, bool lessA, bool lessB, bool lessK, int a, int b, int k){
	if(i < 0)
		return lessA && lessB && lessK;
	if(record[i][lessA][lessB][lessK] > 0)
		return record[i][lessA][lessB][lessK];
	bool maxA = lessA || getbit(a, i) == 1;
	bool maxB = lessB || getbit(b, i) == 1;
	bool maxK = lessK || getbit(k, i) == 1;

	long long int ret = countPairs(i-1, maxA, maxB, maxK, a,  b, k);
	if(maxA)
		ret += countPairs(i-1, lessA, maxB, maxK, a, b, k);
	if(maxB)
		ret += countPairs(i-1, maxA, lessB, maxK, a, b, k);
	if(maxA&&maxB&&maxK)
		ret += countPairs(i-1, lessA, lessB, lessK, a, b, k);

	record[i][lessA][lessB][lessK] = ret;

	return ret;
}
int main(){
	int t;
	cin >> t;
	int n = 0;
	while(n++ < t){
		cout << "Case #" << n << ": ";
		int a, b, k;
		cin >> a >> b >> k;
		memset(record, -1, sizeof(record));
		cout << countPairs(31, false, false, false, a, b, k) << endl;
	}
	return 0;
}
