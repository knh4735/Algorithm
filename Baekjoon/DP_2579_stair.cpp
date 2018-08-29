//2579 계단오르기 Dynamic Programming
#include <stdio.h>

int max(int q, int w){return (q > w ? q : w);}

int main(){
	int n;

	scanf("%d", &n);

	int stair[n+1];
	for(int i = 1; i <= n; i++) scanf("%d", &stair[i]);

	int score[n+1][2];	//score[계단인덱스][0 or 1] 0 : 바로 전 계단을 밟은 경우 / 1 : 바로 전 계단을 안밟은 경우

	score[0][0] = score[0][1] = 0;
	score[1][0] = score[1][1] = stair[1];

	if(n == 1){
		printf("%d", stair[n]);
		return 0;
	}

	for(int i = 2; i <= n; i++){
		score[i][0] = score[i-1][1] + stair[i];
		score[i][1] = max(score[i-2][0], score[i-2][1]) + stair[i];
	}

	printf("%d", max(score[n][0], score[n][1]));

	return 0;
}
