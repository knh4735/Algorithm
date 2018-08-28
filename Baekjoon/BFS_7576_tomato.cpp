//7576 토마토 BFS
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

struct tom {
	int n;
	int m;
};

int n, m;	//m : 가로, n : 세로
queue<tom> tomQ;

//안익은게 남았으면 1 다익으면 0 
int checkPan(int **pan){
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(pan[i][j] == 0) return 1;
	return 0;
}

int main(){
	scanf("%d %d", &m, &n);

	int **pan = (int**) malloc(sizeof(int*) * n);

	//입력
	for(int i = 0; i < n; i++){
		pan[i] = (int*) malloc(sizeof(int) * m);
		for(int j = 0; j < m; j++){
			scanf("%d", &pan[i][j]);
			if(pan[i][j] == 1){
				tom tomTemp = {i, j};
				tomQ.push(tomTemp);
			}
		}
	}

	//day : 지난날짜, ns, ms : 그날 익을 좌표 저장, cnt : ns ms의 인덱스
	int day = 0, cnt = 0;
	tom tomArr[m * n];

	while(checkPan(pan)){
		while(!tomQ.empty()){
			tom tomFr = tomQ.front();
			int i = tomFr.n, j = tomFr.m;

			if(i - 1 >= 0 && pan[i-1][j] == 0){
				tomArr[cnt++] = (tom) {i - 1, j};
				pan[i-1][j] = 1;
			}
			if(i + 1 < n && pan[i+1][j] == 0){
				tomArr[cnt++] = (tom) {i + 1, j};
				pan[i+1][j] = 1;
			}
			if(j - 1 >= 0 && pan[i][j-1] == 0){
				tomArr[cnt++] = (tom) {i, j - 1};
				pan[i][j-1] = 1;
			}
			if(j + 1 < m && pan[i][j+1] == 0){
				tomArr[cnt++] = (tom) {i, j + 1};
				pan[i][j+1] = 1;
			}

			tomQ.pop();
		}

		if(cnt == 0){
			day = -1;
			break;
		}

		for(int i = 0; i < cnt; i++) tomQ.push(tomArr[i]);

		cnt = 0;
		day++;
	}

	printf("%d", day);

	for(int i = 0; i < n; i++) free(pan[i]);
	free(pan);

	return 0;
}
