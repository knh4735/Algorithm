// 2458 키순서 그래프1(플로이드와샬)
#include <stdio.h>

int n, m;
int h[501][501];

int main(){

	scanf("%d %d", &n, &m);

	int a, b;
	for(int i = 0; i < m; i++){
		scanf("%d %d", &a, &b);

		h[a][b] = 1;
	}

	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(h[i][k] + h[k][j] == 2) h[i][j] = 1;
			}
		}
	}

	int cnt = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i != j && h[i][j] == 0 && h[j][i] == 0) break;
			else if(j == n) cnt++;
		}
	}

	printf("%d", cnt);

	return 0;
}

// 조금 복잡하게 푼 
// #include <stdio.h>

// int n, m;
// int h[501][501];

// void dfs(int visit[], int from, int target, int order){
// 	visit[target] = 1;

// 	for(int i = 1; i <= n; i++){
// 		if(visit[i] == 0 && h[target][i] == order){
// 			h[from][i] = order;
// 			dfs(visit, from, i, order);
// 		}
// 	}
// }

// void compare(){
// 	for(int i = 1; i <= n; i++){
// 		int visit[501] = {0, };
// 		for(int j = 1; j <= n; j++){
// 			if(h[i][j] != 0 && visit[j] == 0){
// 				int order = h[i][j];

// 				dfs(visit, i, j, order);
// 			}
// 		}
// 	}
// }

// int main(){

// 	scanf("%d %d", &n, &m);

// 	int a, b;
// 	for(int i = 0; i < m; i++){
// 		scanf("%d %d", &a, &b);

// 		h[a][b] = 1;
// 		h[b][a] = -1;
// 	}

// 	compare();

// 	int cnt = 0;
// 	for(int i = 1; i <= n; i++){
// 		for(int j = 1; j <= n; j++){
// 			if(i != j && h[i][j] == 0) break;
// 			else if(j == n) cnt++;
// 		}
// 	}

// 	printf("%d", cnt);

// 	return 0;
// }
