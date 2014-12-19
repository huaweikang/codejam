#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	for(int i = 0; i < 50; i++)
		printf("%d\t%d\n", i, (1 << i));
	printf("\n");
	return 0;
}
