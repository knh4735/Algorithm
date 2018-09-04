/*
2178 미로탐색 BFS
NxM의 미로, (1, 1)에서 출발해 탈출할 때 지나야하는 최소의 칸 수 구하기 (1은 길 0은 벽)
입력 : 2 <= n, m <= 100 \n ~미로 구조
출력 : 최소의 칸 수
*/
#include <stdio.h>
#include <queue>
using namespace std;

struct loc{
	int y;
	int x;
};

int h, w, cnt;
int map[101][101];
int isVisit[101][101];

int main(){
	scanf("%d %d", &h, &w);

	for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) scanf("%1d", &map[i][j]);

	queue<loc> locQ;

	isVisit[0][0] = 1;
	locQ.push((loc){0, 0});

	while(!locQ.empty()){
		int y = locQ.front().y, x = locQ.front().x;
		locQ.pop();

		if(y == h - 1 && x == w - 1){
			printf("%d", isVisit[y][x]);
			return 0;
		}

		int i = y - 1, j = x;
		if(i >= 0 && isVisit[i][j] == 0 && map[i][j] == 1){
			isVisit[i][j] = isVisit[y][x] + 1;
			locQ.push((loc){i, j});
		}

		i = y + 1, j = x;
		if(i < h && isVisit[i][j] == 0 && map[i][j] == 1){
			isVisit[i][j] = isVisit[y][x] + 1;
			locQ.push((loc){i, j});
		}

		i = y, j = x - 1;
		if(j >= 0 && isVisit[i][j] == 0 && map[i][j] == 1){
			isVisit[i][j] = isVisit[y][x] + 1;
			locQ.push((loc){i, j});
		}

		i = y, j = x + 1;
		if(j < w && isVisit[i][j] == 0 && map[i][j] == 1){
			isVisit[i][j] = isVisit[y][x] + 1;
			locQ.push((loc){i, j});
		}
	}

	return 0;
}
