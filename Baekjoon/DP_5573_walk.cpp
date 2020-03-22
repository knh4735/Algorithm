// 5573 산책 조합론(DP)
#include <stdio.h>

int main(){
	int h, w, n;
	int map[1002][1002] = {0, };

	scanf("%d %d %d", &h, &w, &n);
	for(int i = 1; i <= h; i++)
		for(int j = 1; j <= w; j++)
			scanf("%d", &map[i][j]);

	int cnt[1002][1002] = {0, };
	cnt[1][1] = n;
	for(int r = 1; r <= h; r++){
		for(int c = 1; c <= w; c++){
			cnt[r+1][c] += cnt[r][c] / 2 + (map[r][c] == 0 ? cnt[r][c] % 2 : 0);
			cnt[r][c+1] += cnt[r][c] / 2 + (map[r][c] == 1 ? cnt[r][c] % 2 : 0);
		}
	}
	
	// for(int r = 1; r <= h; r++){
	// 	for(int c = 1; c <= w; c++){
	// 		printf("%d ", cnt[r][c]);
	// 	}
	// 	printf("\n");
	// }

	int mov[2] = {1, 1}; // {r ,c};
	while(mov[0] <= h && mov[1] <= w){
		// printf("%d %d\n", mov[0], mov[1]);
		int dir = map[mov[0]][mov[1]];
		if(cnt[mov[0]][mov[1]] % 2 == 1) mov[dir]++;
		else mov[dir ^ 1]++;
	}

	printf("%d %d", mov[0], mov[1]);

	return 0;
}
