/*
2740 행렬곱셈 Devide & Conquer
N*M크기의 행렬 A와 M*K크기의 행렬 B, 두 행렬을 곱하기 (-100 <= 원소 <= 100)
입력 : n, m  <= 100 \n n~ m개의 원소 \n m, k <= 100 \n m~ k개의 원소
출력 : 행렬의 내용
*/
#include <stdio.h>

int n, m, k;
int a[101][101], b[101][101], c[101][101];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) scanf("%d", &a[i][j]);

	scanf("%d %d", &m, &k);
	for(int i = 0; i < m; i++) for(int j = 0; j < k; j++) scanf("%d", &b[i][j]);

	for(int i = 0; i < n; i++) for(int j = 0; j < k; j++) for(int l = 0; l < m; l++) c[i][j] += a[i][l] * b[l][j];
  
	for(int i = 0; i < n; i++){
		for(int j = 0; j < k; j++) printf("%d ", c[i][j]);
		printf("\n");
	}
  
	return 0;
}
