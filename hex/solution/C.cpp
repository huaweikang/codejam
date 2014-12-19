#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int dx[] = {0, 0, -1, -1, 1, 1}, dy[] = {-1, 1, 0, 1, -1, 0};
const int N = 101;
int n, UP, DOWN, LEFT, RIGHT;
char map[N][N];

int fa[N * N];

int find(int u) {
	return u == fa[u] ? u : fa[u] = find(fa[u]);
}

void merge(int u, int v) {
	if (u == v) {
		return;
	}
	fa[u] = v;
}

void prepare() {
	for (int i = 0; i < n * n + 4; ++i) {
		fa[i] = i;	
	}
	UP = n * n;
	DOWN = n * n + 1;
	LEFT = n * n + 2;
	RIGHT = n * n + 3;
	for (int i = 0; i < n; ++i) {
		if (map[0][i] == 'R') {
			merge(find(i), find(UP));
		}
		if (map[n - 1][n - 1 - i] == 'R') {
			merge(find(n * n - 1 - i), find(DOWN));
		}
		if (map[i][0] == 'B') {
			merge(find(i * n), find(LEFT));
		}
		if (map[i][n - 1] == 'B') {
			merge(find(i * n + n - 1), find(RIGHT));
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (map[i][j] == '.') {
				continue;
			}
			for (int d = 0; d < 6; ++d) {
				int x = i + dx[d], y = j + dy[d];
				if (x >= 0 && x < n && y >= 0 && y < n && map[x][y] == map[i][j]) {
					merge(find(x * n + y), find(i * n + j));
				}
			}
		}
	}
}

bool checkBluewin() {
	return find(LEFT) == find(RIGHT);
}

bool checkRedwin() {
	return find(UP) == find(DOWN);
}

bool checkInvalid() {
	if (checkRedwin() && checkBluewin()) {
		return false;
	}
	int cntr = 0, cntb = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (map[i][j] == 'B') {
				++cntb;
			} else if (map[i][j] == 'R') {
				++cntr;
			}
		}
	}
	if (abs(cntb - cntr) > 1 || cntb > cntr && checkRedwin() || cntr > cntb && checkBluewin()) {
		return false;
	}
	if (checkRedwin() || checkBluewin()) {
		bool cr = checkRedwin(), cb = checkBluewin();
		int flag = false;
		for (int i = 0; i < n && !flag; ++i) {
			for (int j = 0; j < n && !flag; ++j) {
				bool ret = true;
				if (map[i][j] == 'B' && cb ||
					map[i][j] == 'R' && cr) {
					char ch = map[i][j];
					map[i][j] = '.';
					prepare();
					ret = checkRedwin() || checkBluewin();
					map[i][j] = ch;
				}
				if (!ret) {
					flag = true;
				}
			}
		}
		prepare();
		if (!flag) {
			return false;
		}
	}
	return true;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%s", map[i]);
		}
		prepare();
		static int id = 0;
		printf("Case #%d: ", ++id);
		if (!checkInvalid()) {
			puts("Impossible");
		} else if (checkBluewin()) {
			puts("Blue wins");
		} else if (checkRedwin()) {
			puts("Red wins");
		} else {
			puts("Nobody wins");
		}
	}
	return 0;
}
