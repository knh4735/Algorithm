 #include <stdio.h>

int main(){
	int T;
	scanf("%d", &T);

	for(int tc = 0; tc < T; tc++){
		int n;
		int point[2][100001];
		int dp[2][100001] = {0, };

		scanf("%d", &n);

		for(int j = 0; j < 2; j++)
			for(int i = 0; i < n; i++)
				scanf("%d", &point[j][i]);

		dp[0][0] = point[0][0];
		dp[1][0] = point[1][0];

		dp[0][1] = point[0][1] + point[1][0];
		dp[1][1] = point[1][1] + point[0][0];

		for(int i = 2; i < n; i++){
			for(int row = 0; row < 2; row++){
				int max = dp[row][i-2] > dp[1-row][i-2] ? dp[row][i-2] : dp[1-row][i-2];
				max = max > dp[1-row][i-1] ? max : dp[1-row][i-1];

				dp[row][i] = point[row][i] + max;
			}
		}

		printf("%d\n", dp[0][n-1] > dp[1][n-1] ? dp[0][n-1] : dp[1][n-1]);
	}

	return 0;
}
