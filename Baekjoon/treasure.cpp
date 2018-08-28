/*
2589 보물섬 BFS
*/
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

//좌표 구조체
struct loc{
	loc(){y=0;x=0;}
	loc(int _q, int _w) {y = _q; x = _w;}
	int y;
	int x;
};

int h, w, mov = 0;	//높이 너비 이동

int main(){

	scanf("%d %d", &h, &w);
	int c; while ((c = getchar()) != '\n' && c != EOF){}	//버퍼 비움


	int map[h][w];

	loc lArr[h * w];	//시작점 좌표 배열
	int lNum = 0;	//시작점 좌표 배열 인덱스 -> L의 개수

	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			char t;
			scanf("%c", &t);

			//L : 0 , W : -1
			if(t == 'W') map[i][j] = -1;
			else {

				map[i][j] = 0;
				
				//처음 모든 L들을 시작점에 넣음
				lArr[lNum++] = loc(i, j);
			}
		}
			int c; while ((c = getchar()) != '\n' && c != EOF){}	//버퍼 비움
	}

	for(int i = 0; i < lNum; i++){
		queue<loc> locQ;	//좌표 큐에 L하나 넣고 시작
		locQ.push(lArr[i]);
		map[lArr[i].y][lArr[i].x] = 1;

		int m = 0, locArrIdx;
		loc locArr[lNum];

		do{
			locArrIdx = 0;
		
			while(!locQ.empty()){
				loc locTemp = locQ.front();

				int y = locTemp.y, x = locTemp.x;

				if(y + 1 < h && map[y+1][x] == 0){
					map[y+1][x] = 1;
					locArr[locArrIdx++] = loc(y + 1, x);
				}
				if(y - 1 >= 0 && map[y-1][x] == 0){
					map[y-1][x] = 1;
					locArr[locArrIdx++] = loc(y - 1, x);
				}
				if(x + 1 < w && map[y][x+1] == 0){
					map[y][x+1] = 1;
					locArr[locArrIdx++] = loc(y, x + 1);
				}
				if(x - 1 >= 0 && map[y][x-1] == 0){
					map[y][x-1] = 1;
					locArr[locArrIdx++] = loc(y, x - 1);
				}

				locQ.pop();
			}

			for(int q = 0; q < locArrIdx; q++) locQ.push(locArr[q]);

			m++;

		}while(locArrIdx > 0);
		//시작점 하나 순회 끝

		//지도 초기화
		for(int a = 0; a < h; a++) for(int b = 0; b < w; b++) map[a][b] = (map[a][b] == -1 ? -1 : 0);

		if(mov < --m) mov = m;
	}

	printf("%d", mov);

	return 0;
}
