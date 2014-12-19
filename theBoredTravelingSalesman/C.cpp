#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>

#define	MAXN 60
#define	UNREACH 0
#define DEAD	-1
#define ACTIVE	1

using namespace std;

bool graph[MAXN][MAXN];
bool flag[MAXN];

int countReach(int root, vector<vector<int> > &node, vector<int> &state){
	int count = 1; // count root
	flag[root] = true;
	for(vector<int>::iterator it = node[root].begin(); it != node[root].end(); it++)
		if(state[*it] != DEAD && flag[*it] == false)
			count += countReach(*it, node, state);
	return count;
}
int countUnDead(vector<int> &state){
	int num = 0;
	for(vector<int>::iterator it = state.begin(); it != state.end(); it++)
		if(DEAD == state[*it])
			num++;
	return num;
}
int nextElementToVisit(const vector<int> &zip, vector<vector<int> > &node, vector<int> state, stack<int> s, int root){
	int nextNode = -1;
	int head = s.top();
	int unDeadNum = countUnDead(state);
	while(s.empty() == false){
		 for(vector<int>::iterator it = node[s.top()].begin(); it != node[s.top()].end(); it++){
			 if(state[*it] == UNREACH && (nextNode == -1 || zip[*it] < zip[nextNode]) && countReach(root, node, state) == unDeadNum){
				 nextNode = *it;
				 memset(flag, 0, sizeof(flag));
			 }
		 }
		 state[s.top()] = DEAD;
		 unDeadNum--;
		 s.pop();
	}

	return nextNode;
}
void findMinPath(const vector<int> &zip, vector<vector<int> > &node){

	//find source node
	int root = min_element(zip.begin(), zip.end()) - zip.begin();
	int head = root;
	cout << zip[head];
	vector<int> state(zip.size(), UNREACH);	
	stack<int> s;
	state[head] = ACTIVE;
	s.push(head);
	while(s.empty() != true){
		int nextNode = nextElementToVisit(zip, node, state, s, root);
		while(graph[s.top()][nextNode] == false){
			state[s.top()] = DEAD;		//left top node of stack
			s.pop();
		}
		state[nextNode] = ACTIVE;
		s.push(nextNode);
		cout << zip[nextNode];
	}
}
int main(){
	int t;
	cin >> t;
	int k = 0;
	while(k++ < t){
		int n, m;
		vector<int> zip;
		for(int i = 0; i < n; i++){
			int tmp;
			cin >> tmp;
			zip.push_back(tmp);
		}
		vector<vector<int> > node(n);
		memset(graph, false, sizeof(graph));
		for(int i = 0; i < m; i++){
			int x, y;
			cin >> x >> y;
			x--, y--;
			node[x].push_back(y);
			node[y].push_back(x);
			graph[x][y] = true;
			graph[y][x] = true;
		}
		findMinPath(zip, node);
	}
	return 0;
}
