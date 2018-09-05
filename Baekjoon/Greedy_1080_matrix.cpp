/*
1080 행렬 Greedy
NxM의 0,1로만 이루어진 두 행렬을 3x3 범위를 뒤집는 연산을 통해 서로 같게 만들 수 있는 최솟값을 구하기
입력 : 1 <= n, m <= 50 \n ~행렬A ~행렬B
출력 : 최소 연산 횟수
*/
#include <stdio.h>

int n, m, cnt;
char a[53][53], b[53][53];

void op(int q, int w){
	for(int i = q; i < q + 3; i++){
		for(int j = w; j < w + 3; j++){
			if(a[i][j] == -1) break;
			a[i][j] = (a[i][j] == 0 ? 1 : 0);
		}
	}
}

int cmp(){
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(a[i][j] != b[i][j]) return 0;
	return 1;
}

int main(){
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) a[i][j] = b[i][j] = -1;
		
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) scanf("%1d", &a[i][j]);
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) scanf("%1d", &b[i][j]);

	if(n < 3 || m < 3){
		if(cmp() == 1) printf("%d", cnt);
		else printf("-1");

		return 0;
	}

	for(int i = 0; i <= n - 3; i++){
		for(int j = 0; j <= m - 3; j++){
			if(a[i][j] != b[i][j]){
				op(i, j);
				cnt++;
			}
		}
	}

	if(cmp() == 1) printf("%d", cnt);
	else printf("-1");

	return 0;
}
