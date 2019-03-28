/*
15684 사다리조작 DFS (Brute Force)
사다리 타기 게임에서 i번째 열이 i번에 도착하도록 사다리를 추가할 때, 최솟값 구하기 (3까지만)
입력 : 열 개수, 행 개수, 이미 설치된 사다리 개수 2 ≤ N ≤ 10, 1 ≤ H ≤ 30, 0 ≤ M ≤ (N-1)×H \n ~M 사다리의 왼쪽 열번호와 행번호
출력 : 추가하는 사다리의 최소 개수 (3개를 넘거나 불가능하면 -1)
*/
#include <stdio.h>

int n, m, h, r = -1;
int ladder[31][11];

int test(int l_size){
	int flag = 1;
	for(int j = 1; j <= n; j++){
		int p = j;
		for(int i = 1; i <= h; i++){
			if(ladder[i][p] > 0) p++;
			else if(ladder[i][p] < 0) p--;
		}
		if(p != j){
			flag = 0;
			return 0;
		}
	}

	if(flag)
		if(r == -1 || r > l_size)
			r = l_size;

	return 1;
}

void dfs(int y, int x, int l_size){		//테스트, 사다리 추가
	if(l_size >= r && r != -1) return;

	//테스트
	test(l_size);
	//테스트 끝

	if(l_size >= 3) return;

	//사다리 추가
	int j = x + 2;
	for(int i = y; i <= h; i++){
		for(; j < n; j++){
			if(ladder[i][j] == 0 && ladder[i][j+1] == 0){
				ladder[i][j] = 1;
				ladder[i][j+1] = -1;
				dfs(i, j, l_size+1);
				ladder[i][j] = 0;
				ladder[i][j+1] = 0;
			}
		}
		j = 1;
	}

	return;
}

int main(){
	scanf("%d %d %d", &n, &m, &h);

	int y, x;	// 1 <--> -1
	for(int i = 0; i < m; i++){
		scanf("%d %d", &y, &x);
		ladder[y][x] = 1;
		ladder[y][x+1] = -1;
	}

	if(test(0)){
		printf("%d", r);

		return 0;
	}


	for(int i = 1; i <= h; i++){
		for(int j = 1; j < n; j++){
			if(ladder[i][j] == 0 && ladder[i][j+1] == 0){
				ladder[i][j] = 1;
				ladder[i][j+1] = -1;
				dfs(i, j, 1);
				ladder[i][j] = 0;
				ladder[i][j+1] = 0;
			}
		}
	}

	printf("%d", r);

	return 0;
}
