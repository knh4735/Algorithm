/*
11660 구간합구하기5 Dynamic Programming
NxN의 행렬에서 (x1, y1)부터 (x2, y2)까지의 합 출력
입력 : 행렬 크기 1 ≤ N ≤ 1024, 합을 구할 횟수 1 ≤ M ≤ 100000 \n ~N N개의 자연수 ≤ 1000 \n ~M x1 y1 x2 y2 좌표
출력 : ~M 부분합 출력
*/
#include <stdio.h>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

  //sum[i][j] = sum[i][j-1] + k (j > 1, sum[i][0] = 0)
  int k, sum[1025][1025];

	for(int i = 1; i <= n; i++)
		sum[i][0] = 0;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d", &k);
			sum[i][j] = sum[i][j-1] + k;
		}
	}

	for(int i = 0; i < m; i++){
		int sx, sy, ex, ey, r = 0;
		scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
    
		for(int j = sx; j <= ex; j++)
			r += sum[j][ey] - sum[j][sy-1];
		
		printf("%d\n", r);
	}

	return 0;
}
