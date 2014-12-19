#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	//freopen("A-small-practice.in", "r", stdin);
	//freopen("A-small-practice.out", "w", stdout);
	int t, row, ret, k;
	bool flag[20];

	scanf("%d", &t);
	k = 0;
	while(k++ < t){
		
		for(int i = 1; i <= 16; i++)
			flag[i] = false;
		scanf("%d", &row);
		row--;
		for(int i = 0; i < 16; i++){
			int temp;
			scanf("%d", &temp);	
			if(i >= row*4 && i < (row+1)*4)
				flag[temp] = true;
		}	

		int cnt = 0;
		scanf("%d", &row);
		row--;
		for(int i = 0; i < 16; i++){
			int temp;
			scanf("%d", &temp);	
			if(i >= row*4 && i < (row+1)*4 && flag[temp]){
				cnt++;
				ret = temp;
			}
		}

		if(cnt == 1)
			printf("Case #%d: %d\n", k, ret);
		else if(cnt == 0)
			printf("Case #%d: Volunteer cheated!\n", k);
		else
			printf("Case #%d: Bad magician!\n", k);
	}

	return 0;
}
