/*
11659 구간합구하기4 Dynamic Programming
N개의 수 중, i에서 j번째까지의 합을 출력
입력 : 수의 개수 1 ≤ N ≤ 100000, 합을 구할 횟수 1 ≤ M ≤ 100,000 \n N개의 자연수 ≤ 1000 \n ~구간 i j
출력 : ~i부터 j까지의 부분합
*/
#include <stdio.h>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	//sum[i] = sum[i-1] + num[i] (i > 1, sum[0]=0)
	int num[100001], sum[100001];
	sum[0] = 0;

	for(int i = 1; i <= n; i++){
		scanf("%d", &num[i]);
		sum[i] = sum[i-1] + num[i];
	}

	for(int i = 0; i < m; i++){
		int s, e, r;
		scanf("%d %d", &s, &e);
    
		r = sum[e] - sum[s-1];
		printf("%d\n", r);
	}

	return 0;
}
