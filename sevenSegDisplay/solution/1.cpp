#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<iostream>
#include<algorithm>
#include<memory>
#include<map>
#include<queue>
using namespace std;
string str[200];
string shine[10] = {
	"1111110",
	"0110000",
	"1101101",
	"1111001",
	"0110011",
	"1011011",
	"1011111",
	"1110000",
	"1111111",
	"1111011"
};
/*void output(vector<int> &out){
	for (auto &i : out)
		cout<<i;
	cout<<endl;
}*/
int main(){
	int tt;
	int N;
	cin >> tt;
	for (int tcas = 1; tcas <= tt; ++tcas){
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> str[i];
		vector<int> ans;
		int totFail = 0;
		for (int begin = 0; begin < 10; begin ++){

			vector<int> pos;
			pos.resize(7);
			int fail = 0;
			for (int i = 0; i < N; i++){
				int num = ((begin - i) % 10 + 10)% 10;
				//cout<<num<<endl;
				for (int j = 0; j < 7; j++)
					if (str[i][j] == '1'){
						if (shine[num][j] == '0')
							fail = 1;
						else {
							if (pos[j] == 0)
								pos[j] = 1;
							else if (pos[j] == 1) ;
							else if (pos[j] == 2){
								fail = 1;
							}
						}
					}else {
						if (shine[num][j] == '1')
						{
							//0 1
							if (pos[j] == 1)
								fail = 1;
							else pos[j] = 2;
						}else {
							//0 0
						}
					}
				//output(pos);
			}
			int num = ((begin - N) % 10 + 10)% 10;
			
			if (!fail){
				//this can be the next digit.
				vector<int> tmpAns;
				tmpAns.resize(7);
				/*cout << begin <<endl;
				for (auto i : pos)
					cout<<i;
				cout<<endl;*/
				for (int j = 0; j < 7; j++)
				if (shine[num][j] =='1'){
					if (pos[j]==0)
						totFail = 1;
					else if (pos[j] == 1)
						tmpAns[j] = 1;
				}
				if (ans.size() == 0 || ans == tmpAns)
					ans = tmpAns;
				else 
					totFail = 1;
			}
		}

		if (ans.size()==0){
			totFail = 1;
		}
		printf("Case #%d: ", tcas);
		if (totFail){
			printf("ERROR!\n");
			continue;
		}
		for (int i = 0; i < 7; i++)
			printf("%d", ans[i]);
		printf("\n");

	}
}
