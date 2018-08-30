/*
1932 정수삼각형 Dynamic Programming
정수로 만들어진 피라미드 - 맨위부터 차례대로 내려오면서 합이 최대가 되는 경우 찾기
입력 : 삼각형의 크기 1 <= n <= 500 \n ~삼각형의 수들
출력 : 수의 합이 최대가 되는 경우의 값
*/
#include <stdio.h>

int n, m;
int pyramid[501][501];
int sum[501][501];

//범위 초과시 0
int max(int i, int j){return (i > j ? i : j);}

int main(){
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			scanf("%d", &pyramid[i][j]);
		}
	}

	sum[1][1] = pyramid[1][1];

	if(n == 1) {
		printf("%d", sum[1][1]);
		return 0;
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			sum[i][j] = max(sum[i-1][j-1], sum[i-1][j]) + pyramid[i][j];
		}
	}

	for(int i = 1; i <= n; i++) if(m < sum[n][i]) m = sum[n][i];

	printf("%d", m);

	return 0;
}
