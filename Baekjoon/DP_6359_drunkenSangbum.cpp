/*
6359 만취한상범 Dynamic Programming
N 이하의 자연수 중 약수의 개수가 홀수인 수의 개수 구하기
입력 : 테스트케이스 T \n ~수열의 크기 1 <= n <= 100
출력 : ~약수의 개수가 홀수인 수의 개수
*/
#include <stdio.h>

int dp[101] = {0, };	// 2의 배수 = 열림

int cnt(int x){
	if(dp[x] > 0 || x <= 1)
		return dp[x];

	int r = 1;
	for(int i = 2; i < x; i++)
		if(x % i == 0)
			r++;

	dp[x] = r;
	return r;
}

int main(){
	int T;
	scanf("%d", &T);

	dp[1] = 0;

	for(int tc = 0; tc < T; tc++){
		int n, a = 0;
		scanf("%d", &n);

		for(int i = 1; i <= n; i++)
			if(cnt(i) % 2 == 0)
				a++; 

		printf("%d\n", a);
	}

	return 0;
}
