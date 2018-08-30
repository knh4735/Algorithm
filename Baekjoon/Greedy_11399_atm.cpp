/*
11399 ATM Greedy
n명의 사람, i번째 사람이 돈을 뽑는데 걸리는 시간 Pi
각 사람들이 돈을 뽑는데 필요한 시간의 합이 최소가 되는 경우를 구하라
입력 : 사람수 1 <= n <= 1000 \n 1 <= Pi <= 1000
*/
#include <stdio.h>

int main(){
	int n, sum = 0;
	int p[1001];
	scanf("%d", &n);

	for(int i = 0; i < n; i++) scanf("%d", &p[i]);

	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			if(p[i] > p[j]){
				int temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}

	for(int i = n - 1; i >= 0; i--){
		for(int j = i; j >= 0; j--){
			sum += p[j];
		}
	}

	printf("%d", sum);

	return 0;
}
