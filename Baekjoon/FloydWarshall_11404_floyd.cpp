// 11404 플로이드 그래프2(FloydWarshall)
#include <stdio.h>
#include <vector>
using namespace std;

#define INF 2000000000

int main(){
	int n, m;
	int cost[101][101];

	scanf("%d %d", &n, &m);

	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			if(i == j) cost[i][j] = 0;
			else cost[i][j] = INF;
		}
	}
	
	int a, b, c;
	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &a, &b, &c);

		cost[a][b] = min(cost[a][b], c);
	}

	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i == j || cost[i][k] == INF || cost[k][j] == INF) continue;
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
			}
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){\
			if(cost[i][j] == INF) printf("0 ");
			else printf("%d ", cost[i][j]);
		}
		printf("\n");
	}



	return 0;
}
