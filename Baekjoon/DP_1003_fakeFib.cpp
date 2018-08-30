//1003 피보나치함수 Dynamic Programming
//재귀 함수인 피보나치 함수가 있을때 fib(0)은 0을 출력 및 리턴하고, fib(1)은 1을 출력 및 리턴한다
//fib(n)을 호출했을 때 0과 1이 각각 몇번 출력되는지 구하라
//입력 - 테스트 케이스의 개수 \n ~ 0 <= n <= 40
//출력 - ~0이 출력되는 횟수 1이 출력되는 횟수
#include <stdio.h>

int main(){
	int t;
	scanf("%d", &t);

	int n[t], result[41][2];	//result[n][0횟수 1횟수]
	result[0][0] = 1;
	result[0][1] = 0;

	result[1][0] = 0;
	result[1][1] = 1;

	for(int i = 0; i < t; i++){
		scanf("%d", &n[i]);
		
		if(n[i] < 2){
			printf("%d %d\n", result[n[i]][0], result[n[i]][1]);
			continue;
		}

		for(int j = 2; j <= n[i]; j++){
			result[j][0] = result[j-1][0] + result[j-2][0];
			result[j][1] = result[j-1][1] + result[j-2][1];
		}

		printf("%d %d\n", result[n[i]][0], result[n[i]][1]);
	}


	return 0;
}
