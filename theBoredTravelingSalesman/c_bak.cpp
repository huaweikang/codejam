#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
#include <fstream>

#define	MAXN	60

using namespace std;

bool graph[MAXN][MAXN];

bool dfs(const vector<pair<int, int> > &zipAndCityID, stack<int> pos, int n){
	if(n == zipAndCityID.size() - 1)
		return  true;
	int nextNode = zipAndCityID[n + 1].second;
	while(pos.empty() == false && graph[zipAndCityID[pos.top()].second][nextNode] == false)
		pos.pop();
	if(pos.empty() == true)
		return false;
	pos.push(n+1);
	return dfs(zipAndCityID, pos, n+1);	
}
bool checkValid(const vector<pair<int, int> > &zipAndCityID){
	stack<int> pos;
	pos.push(0);
	return dfs(zipAndCityID, pos, 0);
}

bool findMinPath(vector<pair<int, int> > &zipAndCityID, int pos){
	if(pos == zipAndCityID.size())
		return checkValid(zipAndCityID);
	for(int i = pos; i < zipAndCityID.size(); i++){
		swap(zipAndCityID[i], zipAndCityID[pos]);
		if(findMinPath(zipAndCityID, pos+1) == true)
			return true;
		swap(zipAndCityID[i], zipAndCityID[pos]);
	}
	return true;
}
int main(){
	//fstream in("C-small-practice.in");
	fstream in("input");
	int t;
	in >> t;
	int k = 0;
	while(k++ < t){
		cout << "Case #" << k << ": ";
		int n, m;
		in >> n >> m;
		vector<pair<int, int> > zipAndCityID;
		for(int i = 0; i < n; i++){
			int zip;
			in >> zip;
			zipAndCityID.push_back(make_pair(zip, i));
		}
		sort(zipAndCityID.begin(), zipAndCityID.end());

		//initial graph
		memset(graph, false, sizeof(graph));
		for(int i = 0; i < m; i++){
			int x, y;
			in >> x >> y;
			x--, y--;
			graph[x][y] = true;
			graph[y][x] = true;
		}
		findMinPath(zipAndCityID, 1);
		for(vector<pair<int, int> >::iterator it = zipAndCityID.begin(); it != zipAndCityID.end(); it++)
			cout << it->first;
		cout << endl;
	}
	return 0;
}
