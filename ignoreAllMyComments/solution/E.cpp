#include<vector>
#include<string>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

char buf[5050];

int main() {
	printf("Case #1:\n");
	int cnt = 0;
	string ans;
	while (gets(buf)) {
		int l = strlen(buf);
		for (int i = 0; i < l; ++i) {
			if (cnt == 0) {
				if (buf[i] == '/' && i + 1 < l && buf[i + 1] == '*') {
					++cnt;
					++i;
					continue;
				}
			} else {
				if (buf[i] == '*' && i + 1 < l && buf[i + 1] == '/') {
					--cnt;
					++i;
					continue;
				}
				if (buf[i] == '/' && i + 1 < l && buf[i + 1] == '*') {
					++cnt;
					++i;
					continue;
				}
			}
			if (cnt == 0) {
				ans += buf[i];
			}
		}
		if (cnt == 0) {
			ans += '\n';
		}
	}
	cout << ans;
	return 0;
}
