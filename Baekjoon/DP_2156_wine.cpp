/*
2156 포도주시식 Dynamic Programming
n잔의 포도주, 연속된 3잔을 마실순 없을 때 최대의 양을 마실 수 있는 경우를 구함
입력 : 포도주의 잔 수 1 <= n <= 10000 \n ~ 0 <= 포도주의 양 <= 1000
출력 : 최대로 마실 수 있는 포도주의 양
*/
#include <stdio.h>

int n;
int wine[10001];
int sum[10001][2];	//sum[잔][0 이전 잔을 안마심 / 1 이전 잔을 마심]
int m[10001];		//m[n] = n까지의 합 중 최댓값

int max(int q, int w){return (q > w ? q : w);}

int main(){
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%d", &wine[i]);
	}

	sum[1][0] = wine[1];
	sum[1][1] = wine[1];
	m[1] = wine[1];

	if(n == 1){
		printf("%d", wine[1]);
		return 0;
	}

	for(int i = 2; i <= n; i++){
		sum[i][0] = m[i-2] + wine[i];
		sum[i][1] = sum[i-1][0] + wine[i];

		int temp = max(sum[i][0], sum[i][1]);
		m[i] = (m[i-1] < temp ? temp : m[i-1]);
	}

	printf("%d", max(max(sum[n][0], sum[n][1]), sum[n-1][1]));

	return 0;
}
