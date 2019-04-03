/*
14890 경사로 시뮬레이션
NxN 지도에 각 칸의 높이가 저장된다. 높이가 1 차이나는 곳에는 길이 l의 경사로를 설치하여 지나갈 수 있고, 경사로는 겹치거나 범위가 벗어나면 안된다.
이때 지나갈 수 있는 길의 개수 구하기 (행, 열들의 개수)
입력 : 지도의 크기와 경사로의 길이 2 ≤ N ≤ 100, 1 ≤ L ≤ N \n ~N 지도
출력 : 지나갈 수 있는 길의 개수
*/
#include <stdio.h>

int n, l, cnt;
int m[101][101], r[101][101], c[101][101];

int main(){
	scanf("%d %d", &n, &l);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &m[i][j]);
		}
	}

	for(int i = 0; i < n; i++){
		int flag = 0;
		for(int j = 1; j < n; j++){
			if(m[i][j-1] < m[i][j]){
				for(int k = j - 1; k >= j - l; k--){
					if(k < 0 || m[i][k] != m[i][j] - 1 || r[i][k] == 1){
						flag = 1;
						break;
					}
					r[i][k] = 1;
				}
			}
			else if(m[i][j-1] > m[i][j]){
				for(int k = j; k < j + l; k++){
					if(k >= n || m[i][k] != m[i][j-1] - 1 || r[i][k] == 1){
						flag = 1;
						break;
					}
					r[i][k] = 1;
				}
			}

			if(flag) break;
		}

		if(!flag) cnt++;
	}

	for(int j = 0; j < n; j++){
		int flag = 0;
		for(int i = 1; i < n; i++){
			if(m[i-1][j] < m[i][j]){
				for(int k = i - 1; k >= i - l; k--){
					if(k < 0 || m[k][j] != m[i][j] - 1 || c[k][j] == 1){
						flag = 1;
						break;
					}
					c[k][j] = 1;
				}
			}
			else if(m[i-1][j] > m[i][j]){
				for(int k = i; k < i + l; k++){
					if(k >= n || m[k][j] != m[i-1][j] - 1 || c[k][j] == 1){
						flag = 1;
						break;
					}
					c[k][j] = 1;
				}
			}

			if(flag) break;
		}

		if(!flag) cnt++;
	}

	printf("%d", cnt);

	return 0;
}
