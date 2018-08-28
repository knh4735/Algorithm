//7562 나이트의이동 BFS
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

//좌표 구조체
struct loc{
	int y;
	int x;
};

int checkPan(int **pan, int c){
	for(int i = 0; i < c; i++) for(int j = 0; j < c; j++) if(pan[i][j] == 0) return 1;
	return 0;
}

int main(){
	int n;	//테스트 수

	scanf("%d", &n);

	for(int i = 0; i < n; i++){

		int c; 	//칸 수

		scanf("%d", &c);

		//순회 확인 배열 초기화
		int **pan = (int**) malloc(sizeof(int*) * c);
		for(int j = 0; j < c; j++) pan[j] = (int*) calloc(c, sizeof(int));


		int q, w, flag = 0, cnt = 0, move = 0;		//cnt : locArr 인덱스, m : 이동 횟수
		loc locArr[c*c];
		queue<loc> locQ;	//좌표 큐

		//시작점 푸시
		scanf("%d %d", &q, &w);
		locQ.push((loc){w, q});
		pan[w][q] = 1;

		//목표 지점 설정
		scanf("%d %d", &q, &w);
		loc target = {w, q};

		while(checkPan(pan, c)){

			while(!locQ.empty()){
				loc locTemp = locQ.front();

				int y = locTemp.y, x = locTemp.x;

				if(y == target.y && x == target.x){
					flag = 1;
					break;
				}

				q = y + 1, w = x + 2;
				if(q < c && w < c && pan[q][w] == 0){
					locArr[cnt++] = (loc){q, w};
					pan[q][w] = 1;
				}

				q = y + 1, w = x - 2;
				if(q < c && w >= 0 && pan[q][w] == 0){
					locArr[cnt++] = (loc){q, w};
					pan[q][w] = 1;
				}

				q = y - 1, w = x + 2;
				if(q >= 0 && w < c && pan[q][w] == 0){
					locArr[cnt++] = (loc){q, w};
					pan[q][w] = 1;
				}

				q = y - 1, w = x - 2;
				if(q >= 0 && w >= 0 && pan[q][w] == 0){
					locArr[cnt++] = (loc){q, w};
					pan[q][w] = 1;
				}
				
				q = y + 2, w = x + 1;
				if(q < c && w < c && pan[q][w] == 0){
					locArr[cnt++] = (loc){q, w};
					pan[q][w] = 1;
				}
				
				q = y - 2, w = x + 1;
				if(q >= 0 && w < c && pan[q][w] == 0){
					locArr[cnt++] = (loc){q, w};
					pan[q][w] = 1;
				}
				
				q = y + 2, w = x - 1;
				if(q < c && w >= 0 && pan[q][w] == 0){
					locArr[cnt++] = (loc){q, w};
					pan[q][w] = 1;
				}
				
				q = y - 2, w = x - 1;
				if(q >= 0 && w >= 0 && pan[q][w] == 0){
					locArr[cnt++] = (loc){q, w};
					pan[q][w] = 1;
				}


				locQ.pop();
			}

			if(flag == 1) break;

			for(int j = 0; j < cnt; j++) locQ.push(locArr[j]);

			cnt = 0;
			move++;
		}

		printf("%d\n", move);

		for(int j = 0; j < c; j++) free(pan[j]);
		free(pan);
	}

	return 0;
}
