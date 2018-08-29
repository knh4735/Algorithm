//1149 RGB거리 Dynamic Programming
//1 <= num of house <= 1000
//cost(R) cost(G) cost(B) of each house
//인접한 집은 다른색으로 칠해야만 할때 모든 집을 칠하는 최소 비용
#include <stdio.h>

int min(int q, int w){return (q > w ? w : q);}

int main(){
	int n;
	scanf("%d", &n);

	int cost[n][3], result[n][3];	//cost[집번호][해당집rgb], result[집누적][마지막집rgb]
	for(int i = 0; i < n; i++) scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);

	result[0][0] = cost[0][0];
	result[0][1] = cost[0][1];
	result[0][2] = cost[0][2];


	for(int i = 1; i < n; i++){
		result[i][0] = min(result[i-1][1], result[i-1][2]) + cost[i][0];
		result[i][1] = min(result[i-1][0], result[i-1][2]) + cost[i][1];
		result[i][2] = min(result[i-1][0], result[i-1][1]) + cost[i][2];
	}
	

	printf("%d", min(min(result[n-1][0], result[n-1][1]), result[n-1][2]));

	return 0;
}
