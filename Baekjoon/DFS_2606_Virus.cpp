/*
2606 바이러스 DFS
각 컴퓨터들이 연결된 네트워크들이 주어질 때, 1번 컴퓨터가 감염되어 전염되는 컴퓨터의 수를 구하기
입력 : 컴퓨터의 수 <= 100 \n 컴퓨터들이 연결된 쌍의 수 \n ~연결된 컴퓨터1 2
출력 : 전염되는 컴퓨터의 수
*/
#include <stdio.h>

int n, p, cnt;
int net[101][101], isVisit[101];

void dfs(int cur){
	for(int i = 1; i <= n; i++){
		if(net[cur][i] == 1 && isVisit[i] == 0){
			cnt++;
			isVisit[i] = 1;
			dfs(i);
		}
	}

}

int main(){
	scanf("%d", &n);
	scanf("%d", &p);

	for(int i = 0; i < 101; i++) for(int j = 0; j < n; j++) net[i][j] = -1;
	for(int i = 0; i < p; i++){
		int q, w;
		scanf("%d %d", &q, &w);
		net[q][w] = 1;
		net[w][q] = 1;
	}

	isVisit[1] = 1;
	dfs(1);

	printf("%d", cnt);


	return 0;
}
