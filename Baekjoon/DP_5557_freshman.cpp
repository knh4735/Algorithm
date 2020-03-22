// 5557 1학년 조합론(DP)
#include <stdio.h>

int n;
int a[101];
long long dp[101][21]; // i번째 수까지 수식 값이 j가 나오는 경우의 수

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);

	dp[0][a[0]] = 1ll;
	for(int i = 1; i < n-1; i++){
		for(int j = 0; j <= 20; j++){
			if(dp[i-1][j] == 0ll) continue;

			if(j + a[i] <= 20) dp[i][j + a[i]] += dp[i-1][j];
			if(j - a[i] >= 0) dp[i][j - a[i]] += dp[i-1][j];
		}
	}
	
	// printf("   ");
	// for(int i = 0; i < n-1; i++) printf("%2d ", a[i]);
	// for(int j = 0; j <= 20; j++){
	// 	printf("\n%2d ", j);
	// 	for(int i = 0; i < n-1; i++){
	// 		printf("%2d ", dp[i][j]);
	// 	}
	// }
	// printf("\n");

	printf("%lld", dp[n-2][a[n-1]]);

	return 0;
}
