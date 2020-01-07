/*
2468 안전영역 BFS
각 칸의 높이가 주어진 지도에서, 강우량에 따라 침수되지 않은 구역의 개수 최댓값 구하기
입력 : 지도의 크기 2 <= N <= 100 \n ~각 칸의 높이
출력 : 침수되지 않는 구역 개수의 최댓값
*/


#include <stdio.h>
#include <queue>
using namespace std;

int n, ans = 1;
int map[101][101];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

struct pos {
	int r;
	int c;
};

int main(){
	scanf("%d", &n);

	for(int i = 0; i < n ; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &map[i][j]);


	int rain = 1, flag = 0;
	do {
		//printf("RAIN %d\n", rain);
		int visit[101][101] = {0, };
		int cnt = 0;

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(visit[i][j] == 1 || map[i][j] <= rain) continue;
				visit[i][j] = 1;
				cnt++;

				queue<pos> q;
				//printf("AREA %d %d\n", i, j);
				q.push((pos){i, j});

				while(!q.empty()){
					pos p = q.front();
					q.pop();

					for(int k = 0; k < 4; k++){
						int nr = p.r + dr[k];
						int nc = p.c + dc[k];

						if(nc < 0 || nr < 0 || nc >= n || nr >= n) continue;
						if(visit[nr][nc] == 1 || map[nr][nc] <= rain) continue;
						visit[nr][nc] = 1;

						//printf("%d %d\n", nr, nc);
						q.push((pos){nr, nc});
					}
				}
			}
		}

		if(cnt == 0) flag = 1;
		if(ans < cnt) ans = cnt;
		rain++;
	} while(flag == 0);

	printf("%d", ans);

	return 0;
}
