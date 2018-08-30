//9663 N-Queen Backtracking
//입력 : 1 <= N < 15
//출력 : N x N의 체스판에서 N개의 퀸이 서로 공격할 수 없게 놓는 방법의 수
#include <stdio.h>
#include <stdlib.h>

int n, result;
int pan[15][15];

struct loc{
	loc(int _y, int _x) {y = _y; x = _x;}
	loc() {y = 0; x = 0;}
	int y;
	int x;
};

//추가하려는 퀸과 공격범위가 겹치는 퀸이 있는지 확인 - 있으면 0 없으면 1
int checkQueen(int q, int w, int t, loc isQueen[]){
	for(int i = 0; i < t; i++){
		if(q == isQueen[i].y || w == isQueen[i].x
			|| q + w == isQueen[i].y + isQueen[i].x
			|| q - isQueen[i].y == w - isQueen[i].x) return 0;

	}
	return 1;
}

void dfs(int c, int t, loc isQueen[]){	//추가할열번호, 현재 방문수, 방문표
	if(t == n){
		result++;
		return;
	}

	for(int i = 0; i < n; i++){
		if(checkQueen(i, c, t, isQueen)){
			isQueen[t] = loc(i, c);
			dfs(c+1, t+1, isQueen);
		}
	}
	return;
}


int main(){
	scanf("%d", &n);

	//한 열씩 늘려가는 방식
	for(int i = 0; i < n; i++){
		loc isQueen[n*n];
		int t = 0;

		isQueen[t] = loc(i, 0);
		dfs(1, t+1, isQueen);
	}

	printf("%d", result);

	return 0;
}
