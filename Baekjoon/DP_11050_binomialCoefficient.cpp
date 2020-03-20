// 11050 이항계수1 조합론(DP)
#include <stdio.h>

int dp[1001][1001];

int c(int n, int k){
	if(dp[n][k] != 0) return dp[n][k];
	if(k == 0 || n == k){
		dp[n][k] = 1;
		return 1;
	}

	dp[n][k] = (c(n-1, k-1) + c(n-1, k)) % 10007;
	return dp[n][k];
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);

	printf("%d", c(n,k));

	return 0;
}
