#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Rect{		//Rectangular area
	int x1, y1, x2, y2;
	Rect(int a, int b, int c, int d):x1(a), y1(b), x2(c), y2(d){
	};
};

unsigned long long int calculateDistance(vector<Rect> &rectAreas, int xCh, int yCh){
	unsigned long long int  ret = 0;
	for(vector<Rect>::iterator it = rectAreas.begin(); it != rectAreas.end(); it++){
		unsigned long long int xDis;
		if(xCh >= it->x2)
			xDis = (xCh*2 - it->x2 - it->x1) * (it->x2 - it->x1 + 1) * (it->y2 - it->y1 + 1) / 2;
		else if(xCh <= it->x1)
			xDis = (it->x2 + it->x1 - xCh*2) * (it->x2 - it->x1 + 1) * (it->y2 - it->y1 + 1) / 2;
		else{
			xDis = ((it->x2 - xCh) * (it->x2 - xCh + 1) + (xCh - it->x1) * (xCh - it->x1 + 1)) * (it->y2 - it->y1 + 1) / 2;
		}
		unsigned long long int yDis;
		if(yCh >= it->y2)
			yDis = (yCh*2 - it->y2 - it->y1) * (it->y2 - it->y1 + 1) * (it->x2 - it->x1 + 1) / 2;
		else if(yCh <= it->y1)
			yDis = (it->y2 + it->y1 - yCh*2) * (it->y2 - it->y1 + 1) * (it->x2 - it->x1 + 1) / 2;
		else{
			yDis = ((it->y2 - yCh) * (it->y2 - yCh + 1) + (yCh - it->y1) * (yCh - it->y1 + 1)) * (it->x2 - it->x1 + 1) / 2;
		}

		ret += xDis + yDis;
	}
	return ret;
}
struct myFunc{
	bool operator()(pair<int, int> &a, pair<int, int> &b){
		return a.first < b.first || (a.first == b.first && a.second < b.second);
	}
} myCmp;
int main(){
	int t;
	cin >> t;
	int k = 0;
	while(k++ < t){
		cout << "Case #" << k << ":";
		int b;	//num of block
		cin >> b;
		vector<Rect> rectAreas;
		//vector<pair<int, int> > people;

		for(int i = 0; i < b; i++){
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			rectAreas.push_back(Rect(x1, y1, x2, y2));
			/*for(int i = x1; i <= x2; i++)
				for(int j = y1; j <= y2; j++)
					people.push_back(make_pair(i, j));*/
		}

		//sort(people.begin(), people.end(), myCmp);

		int minX, minY;
	       	unsigned long long int minDis = INT_MAX;

		/*for(vector<pair<int, int> >::iterator it = people.begin(); it != people.end(); it++){
			int dis = calculateDistance(rectAreas, it->first, it->second);
			if(dis < minDis){
				minX = it->first;
				minY = it->second;
				minDis = dis;
			}
		}*/
		for(vector<Rect>::iterator itChoose = rectAreas.begin(); itChoose != rectAreas.end(); itChoose++){
			for(int i = itChoose->x1; i <= itChoose->x2; i++)
				for(int j = itChoose->y1; j <= itChoose->y2; j++){
					unsigned long long int dis = calculateDistance(rectAreas, i, j);
					if(dis < minDis){
						minX = i;
						minY = j;
						minDis = dis;
					}
					else if(dis == minDis && (i < minX || (i == minX && j < minY))){
						minX = i;
						minY = j;
					}
				}
		}

		cout << " " << minX << " " << minY << " " << minDis << endl;
	}
	return 0;
}
