/*
11403 경로찾기 DFS
노드 i에서 j로 가는 간선이 있는 경우 1을 나타내는 행렬을 이용해 각 노드에서 다른 노드로 이동 가능한지를 나타내는 인접행렬 출력
입력 : 정점 개수 <= 100 \n ~각 노드에서 다른 노드로의 이동 간선 존재 여부 행렬
출력 : 각 노드의 이동 가능 여부 행렬
*/
#include <stdio.h>

int n;
char a[101][101], r[101][101];

void dfs(int i, int j){
	for(int k = 0; k < n; k++){
		if(a[j][k] == 1 && r[i][k] == 0){
			r[i][k] = 1;
			dfs(i, k);
		}
	}
}


int main(){
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[i][j] == 1 && r[i][j] == 0){
				r[i][j] = 1;
				dfs(i, j);
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			printf("%d ", r[i][j]);
		
		printf("\n");
	}

	return 0;
}
