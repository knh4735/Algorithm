/*
14500 테트로미노 DFS (Brute Force)
테트리스에 사용되는 도형들을 테트로미노라고 한다. 각 칸에 숫자가 적힌 NxM의 판에서 적당한 테트로미노를 올렸을 때 칸에 있는 숫자의 합이 최대가 되는 최댓값을 구하기
입력 : 판의 크기 (4 ≤ N, M ≤ 500) \n ~N M개의 숫자들
출력 : 같은 테트로미노에 포함되는 숫자 합의 
*/
#include <stdio.h>

int n, m, max;
int pan[501][501];
int is_visit[501][501];

void dfs(int r, int c, int num, int cnt){
	if(cnt == 4){
		max = num > max ? num : max;

		return;
	}
	int flag[4] = {0,};   //각 방향 별 이동 가능 여부

	int nr = r,
		nc = c + 1;
	if(nc < m && is_visit[nr][nc] == 0){	//>
		flag[0] = 1;
		is_visit[nr][nc] = 1;
		dfs(nr, nc, num + pan[nr][nc], cnt+1);
		is_visit[nr][nc] = 0;
	}

	nr = r + 1;
	nc = c;
	if(nr < n && is_visit[nr][nc] == 0){	//v
		flag[1] = 1;
		is_visit[nr][nc] = 1;
		dfs(nr, nc, num + pan[nr][nc], cnt+1);
		is_visit[nr][nc] = 0;
	}

	nr = r;
	nc = c - 1;
	if(nc >= 0 && is_visit[nr][nc] == 0){	//<
		flag[2] = 1;
		is_visit[nr][nc] = 1;
		dfs(nr, nc, num + pan[nr][nc], cnt+1);
		is_visit[nr][nc] = 0;
	}

	nr = r - 1;
	nc = c;
	if(nr >= 0 && is_visit[nr][nc] == 0){	//^
		flag[3] = 1;
		is_visit[nr][nc] = 1;
		dfs(nr, nc, num + pan[nr][nc], cnt+1);
		is_visit[nr][nc] = 0;
	}

	if(cnt > 2) return;

  //cnt <= 2인 경우 두가지 방향으로 이동 
  for(int i = 0; i < 4; i++){
		if(flag[i] == 0) continue;
		int nr1, nr2, nc1, nc2;
		switch(i){
			case 0: nr1 = r; nc1 = c+1; break;
			case 1: nr1 = r+1; nc1 = c; break;
			case 2: nr1 = r; nc1 = c-1; break;
			case 3: nr1 = r-1; nc1 = c; break;
		}
		for(int j = 0; j < 4; j++){
			if(i == j || flag[j] == 0) continue;
			switch(j){
				case 0: nr2 = r; nc2 = c+1; break;
				case 1: nr2 = r+1; nc2 = c; break;
				case 2: nr2 = r; nc2 = c-1; break;
				case 3: nr2 = r-1; nc2 = c; break;
			}
			is_visit[nr1][nc1] = 1;
			is_visit[nr2][nc2] = 1;
			dfs(nr1, nc1, num + pan[nr1][nc1] + pan[nr2][nc2], cnt+2);
			dfs(nr2, nc2, num + pan[nr1][nc1] + pan[nr2][nc2], cnt+2);
			is_visit[nr1][nc1] = 0;
			is_visit[nr2][nc2] = 0;

		}
	}

	return;
}

int main(){
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d", &pan[i][j]);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			is_visit[i][j] = 1;
			dfs(i, j, pan[i][j], 1);
			is_visit[i][j] = 0;
		}
	}

	printf("%d", max);

	return 0;
}
