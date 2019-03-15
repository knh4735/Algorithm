/*
11049 행렬곱셈순서 Dynamic Programming
NxM 행렬과 MxK 행렬을 곱할 때 곱셈 계산 횟수는 NxMxK. 여러 개의 행렬을 곱할 때에 연산 순서에 따라 달라지는 계산 횟수의 최솟 값을 구하기
입력 : 행렬의 개수 1 ≤ N ≤ 500 \n ~N 행렬의 행, 열의 수 1 ≤ r, c ≤ 500
출력 : 곱셈 연산의 최솟값 (최악의 경우에도 2^31 - 1)
*/
#include <stdio.h>

int INT_MAX = 2147483647;
int n;
int r[501], c[501];
int dp[501][501];	//dp[i][j] <- i부터 j까지의 최소 계산 값

int min(int i, int j){return i < j ? i : j;}

int cal(int i, int j){
	if(dp[i][j] < INT_MAX) return dp[i][j];	//이미 계산된 값
	if(i == j) return 0;

	//i부터 j 사이를 나눠 재귀적으로 계산한 최솟값을 저장
	for(int k = i; k < j; k++)
		dp[i][j] = min(dp[i][j], cal(i, k) + cal(k+1, j) + r[i] * c[k] * c[j]);

	return dp[i][j];
}

int main(){
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d %d", &r[i], &c[i]);

	//최댓값으로 초기화
	for(int i = 0; i < 501; i++)
		for(int j = 0; j < 501; j++)
			dp[i][j] = INT_MAX;

	//0부터 n-1까지의 최소 계산값 출력
	printf("%d", cal(0, n-1));

	return 0;
}
