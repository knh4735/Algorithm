// 1256 사전 조합론(DP)
#include <stdio.h>
#include <algorithm>

#define MAX_SIZE 1000000000

int dp[101][101];

int get_dp(int a, int z){
	if(dp[a][z] != 0) return dp[a][z];

	if(dp[z][a] != 0){
		dp[a][z] = dp[z][a];
		return dp[a][z];
	}

	if(a == 0 || z == 0){
		dp[a][z] = 1;
		return dp[a][z];
	}

	dp[a][z] = std::min(get_dp(a-1, z) + get_dp(a, z-1), MAX_SIZE + 1);
	return dp[a][z];
}

void set_word(char* s, int a, int z, int k){
	if(a == 0) {
		while(z > 0){
			*s = 'z';
			s++;
			z--;
		}
		return;
	} else if(z == 0) {
		while(a > 0) {
			*s = 'a';
			s++;
			a--;
		}
		return;
	}

	if(dp[a-1][z] >= k){
		*s = 'a';
		s++;
		set_word(s, a-1, z, k);
	} else {
		*s = 'z';
		s++;
		set_word(s, a, z-1, k - dp[a-1][z]);
	}
}

int main(){
	int n, m, k;
	char s[201] = {0, };
	scanf("%d %d %d", &n, &m, &k);

	get_dp(n, m);

	if(dp[n][m] < k){
		printf("-1");
		return 0;
	}

	set_word(s, n, m, k);

	printf("%s", s);

	return 0;
}
