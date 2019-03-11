/*
2167 2차원배열의합 Dynamic Programming
최대 300x300 크기의 2차원 배열에서 (i,j)부터 (x,y)까지의 합
입력 : 테스트케이스의 수 <= 10000 \n ~i, j, x, y (i <= x , j <= y)
출력 : ~합
*/
#include <stdio.h>

int main(){
	int a[301][301], b[301][301];
	int n, m;
	scanf("%d %d", &n, &m);

	for(int i = 1; i <= n; i++){
		b[i][0] = 0;
		for(int j = 1; j <= m; j++){
			scanf("%d", &a[i][j]);
			b[i][j] = b[i][j-1] + a[i][j];
		}
	}

	int k;
	int sx, sy, ex, ey;
	scanf("%d", &k);

	for(int t = 0; t < k; t++){
		int sum = 0;
		scanf("%d %d %d %d", &sy, &sx, &ey, &ex);

		for(int i = sy; i <= ey; i++)
			sum += b[i][ex]-b[i][sx-1];

		printf("%d\n", sum);
	}



	return 0;
}
