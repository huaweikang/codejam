#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countNode(vector<bool> &flag, vector<vector<int> > &node, int root){ // count the most nodes to be a full binary tree
	flag[root] = true;
	if(node[root].size() <= 2)
		return 1;
	int firstMax = -1, secondMax = -1;	
	for(int i = 0; i < node[root].size(); i++){
		if(flag[node[root][i]] == false ){
			int tmp = countNode(flag, node, node[root][i]);
			if(firstMax < tmp){
				secondMax = firstMax;
				firstMax = tmp;
			}
			else if(secondMax < tmp)
				secondMax = tmp;
		}
	}
	if(firstMax > 0 && secondMax > 0)
		return firstMax + secondMax + 1;
	return 1;
}
int main(){
	int t;
	cin >> t;
	int k = 0;
	while(k++ < t){
		cout << "Case #" << k << ":";
		int n;
		cin >> n;
		vector<vector<int> > node(n);
		for(int i = 0; i < n-1; i++){
			int x, y;
			cin >> x >> y;
			x--;
			y--;
			node[x].push_back(y);
			node[y].push_back(x);
		}
		//root 
		int minDel = n;
		for(int root = 0; root < n; root++){
			vector<bool> flag(n, false);
			flag[root] = true;
			if(node[root].size() < 2)
				minDel = min(minDel, n-1);
			else if(node[root].size() == 2)
				minDel = min(minDel, n - 1 - countNode(flag, node, node[root][0]) - countNode(flag, node, node[root][1]));
			else
				minDel = min(minDel, n - countNode(flag, node, root));
		}
		cout << " " << minDel << endl;
	}
}
