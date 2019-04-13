/*
1949 등산로조성 DFS(Brute Force)
NxN 지도의 각 칸에 높이가 입력된다. 가장 높은 봉우리부터 현재 지점보다 낮은 지점으로 등산로를 이어서 조성한다. 필요한 경우 한 곳에 K만큼 파서 높이를 낮출 수 있다.
가장 긴 등산로의 길이를 구하기
입력 : TC \n 지도 크기 3 ≤ N ≤ 8, 공사 가능 깊이 1 ≤ K ≤ 5 \n ~N N개 칸의 높이 정보
출력 : 가능한 가장 긴 등산로의 
*/
#include <stdio.h>
#include <string.h>

int n, k, result;
int map[9][9];
bool visited[9][9];


void dfs(int r, int c, int cnt, bool digged){
	int dr[4] = {0, 0, 1, -1},
		dc[4] = {1, -1, 0, 0};
	bool flag = false;

	//printf("%d %d %d %d %d\n",r,c, map[r][c],cnt,digged);

	for(int i = 0; i < 4; i++){
		int nr = r + dr[i],
			nc = c + dc[i];

		if(nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc])
			continue;
	

		if(map[nr][nc] < map[r][c]){
			flag = true;
			visited[nr][nc] = true;
			dfs(nr, nc, cnt+1, digged);
			visited[nr][nc] = false;
		}
		else if(!digged && map[nr][nc] - k < map[r][c]){
			flag = true;

			int tmp = map[nr][nc];

			map[nr][nc] = map[r][c] - 1;
			visited[nr][nc] = true;
			dfs(nr, nc, cnt+1, true);
			visited[nr][nc] = false;
			map[nr][nc] = tmp;
		}
	}

	if(!flag && result < cnt){
		result = cnt;
		//printf("%d %d\n\n",cnt, result);
	}
	//else if(!flag) printf("\n");

	return;
}


int main(){
	int T;
	scanf("%d", &T);

	for(int tc = 1; tc <= T; tc++){
		result = 0;
		memset(visited, 0, sizeof(visited));

		scanf("%d %d", &n, &k);

		int max = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				scanf("%d", &map[i][j]);
				if(max < map[i][j]) max = map[i][j];
			}
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(map[i][j] == max){
					//printf("\nStart %d %d\n", i, j);
					visited[i][j] = true;
					dfs(i, j, 1, false);
					visited[i][j] = false;
				}
			}
		}

		printf("#%d %d\n", tc, result);
	}

	return 0;
}
