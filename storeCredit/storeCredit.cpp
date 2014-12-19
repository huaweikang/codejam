#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	freopen("A-large-practice.in", "r", stdin);
	freopen("output", "w", stdout);

	int n, credit, itemNum;
	int k = 0;
	scanf("%d", &n);
	while(k++ < n){
		scanf("%d", &credit);
		scanf("%d", &itemNum);
		vector<pair<int, int> > items;
		for(int i = 0; i < itemNum; i++){
			int item;
			scanf("%d", &item);
			items.push_back(make_pair(item, i+1));
		}
		//sort items
		sort(items.begin(), items.end());
		for(int i = 0, j = itemNum-1; i < j;){
			if(items[i].first + items[j].first == credit){
				if(items[i].second < items[j].second)
					printf("Case #%d: %d %d\n", k, items[i].second, items[j].second);
				else
					printf("Case #%d: %d %d\n", k, items[j].second, items[i].second);
				break;
			}
			else if(items[i].first + items[j].first < credit)
				i++;
			else
				j--;
		}
	}
}
