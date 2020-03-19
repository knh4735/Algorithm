// 2725 보이는점의개수 정수론(유클리드호제법)
#include <stdio.h>

int euclidean(int a, int b){
	int tmp;
	while(b > 0){
		tmp = a;
		a = b;
		b = tmp % a;
	}
	return a;
}

int main(){
	int dp[1001][1001] = {0, };
	int T;
	scanf("%d", &T);

	for(int tc = 0; tc < T; tc++){
		int n;
		scanf("%d", &n);

		int cnt = 2; // {1,0} {0,1}
		dp[0][1] = 1;
		dp[0][1] = 1;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(dp[i][j] == 1){
					cnt++;
					continue;
				} else if(dp[i][j] == 2) continue;
				else {
					if(euclidean(i, j) == 1){
						cnt++;
						dp[i][j] = 1;
					} else {
						dp[i][j] = 2;
					}
				}
			}
		}

		printf("%d\n", cnt);
	}

	return 0;
}
