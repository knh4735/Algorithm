/*
N개의 수열 사이에 N-1개의 연산자를 하나씩 끼워넣어 생기는 식들 중 계산 결과가 최대, 최소인 값을 구하기. (연산은 무조건 앞에서부터)
입력 : 수열의 개수 2 ≤ N ≤ 11 \n N개의 수열 값 (1 ≤ Ai ≤ 100) \n 4가지 연산자의 개수 (+ - * / 순서)
출력 : 연산 결과의 최댓값 \n 연산 결과의 최솟값
*/
#include <stdio.h>

int n, max = -1000000000, min = 1000000000;
int a[101];
int op[4];

void dfs(int o, int sum, int cnt){
	switch(o){
		case 0: sum += a[cnt]; break;
		case 1: sum -= a[cnt]; break;
		case 2: sum *= a[cnt]; break;
		case 3: sum /= a[cnt]; break;
	}

	if(cnt >= n-1){
		max = sum > max ? sum : max;
		min = sum < min ? sum : min;

		return;
	}

	for(int i = 0; i < 4; i++){
		if(op[i] > 0){
			op[i]--;
			dfs(i, sum, cnt+1);
			op[i]++;
		}
	}

	return;
}

int main(){
	scanf("%d", &n);

	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 0; i < 4; i++) scanf("%d", &op[i]);

	for(int i = 0; i < 4; i++){
		if(op[i] > 0){
			op[i]--;
			dfs(i, a[0], 1);
			op[i]++;
		}
	}

	printf("%d\n%d", max, min);

	return 0;
}
