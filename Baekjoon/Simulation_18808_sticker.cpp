// 18808 스티커붙이기 삼성모의고사
#include <stdio.h>

int n, m, k;
int size[101][2];
int cnt[101];
int s[101][11][11][4];

int total = 0;
int note[41][41] = {0,};

void fill(int r, int c, int si, int d){
	int R = size[si][d%2], C = size[si][(d%2) ^ 1];

	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			if(s[si][i][j][d] == 1) note[i + r][j + c] = s[si][i][j][d];
		}
	}

	total += cnt[si];
	return;
}

int fit(int si, int d){
	int R = size[si][d%2], C = size[si][(d%2) ^ 1];

	if(n < R || m < C) return 0;
	for(int i = 0; i <= n - R; i++){
		for(int j = 0; j <= m - C; j++){
			int flag = 1;
			for(int r = 0; r < R; r++){
				for(int c = 0; c < C; c++){
					if(s[si][r][c][d] == 1 && note[i + r][j + c] == 1){
						// printf("%d %d %d %d\n", i, r, j, c);
						flag = 0;
						break;
					}
				}
				if(flag == 0) break;
			}

			if(flag == 1){
				fill(i, j, si, d);

				// printf("Sticker %d / Direction %d / (%d, %d) Total: %d\n", si, d, i, j, total);
				// for(int i = 0; i < n; i++){
				// 	for(int j = 0; j < m; j++) printf("%d ", note[i][j]);
				// 	printf("\n");
				// }

				return 1;
			}
		}
	}

	return 0;
}

int main(){
	scanf("%d %d %d", &n, &m, &k);

	int r_sticker, c_sticker, tmp;
	for(int i = 0; i < k; i++){
		scanf("%d %d", &r_sticker, &c_sticker);
		size[i][0] = r_sticker--;
		size[i][1] = c_sticker--;

		for(int r = 0; r <= r_sticker; r++){
			for(int c = 0; c <= c_sticker; c++){
				scanf("%d", &tmp);
				
				s[i][r][c][0] = tmp;	// 0
				s[i][c][r_sticker-r][1] = tmp;	// 90
				s[i][r_sticker-r][c_sticker-c][2] = tmp;	// 180
				s[i][c_sticker-c][r][3] = tmp;	// 270

				if(tmp == 1) cnt[i]++;
			}
		}

		// printf("\n%d %d\n", size[i][0], size[i][1]);
		// for(int j = 0; j < 4; j++){
		// 	printf("\n%d %d\n", i, 90*j);
		// 	for(int r = 0; r < size[i][j%2]; r++){
		// 		for(int c = 0; c < size[i][(j%2)^1]; c++)
		// 			printf("%d", s[i][r][c][j]);
		// 		printf("\n");
		// 	}
		// }
		// printf("\n");
	}

	for(int i = 0; i < k; i++){
		for(int j = 0; j < 4; j++){
			int is_fit = fit(i, j);
			if(is_fit == 1) break;
		}
	}

	printf("%d", total);

	return 0;
}
