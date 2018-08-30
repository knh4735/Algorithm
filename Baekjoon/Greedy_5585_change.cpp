/*
5585 거스름돈 Greedy
1000원을 냈을 때 거스름돈의 동전 개수를 구하기 (동전 종류는 500 100 50 10 5 1)
입력 : 가격 1 <= n < 1000
출력 : 거스름돈 동전의 수
*/
#include <stdio.h>

int main(){
	int n, a = 0;
	scanf("%d", &n);

	int change[6] = {500, 100, 50, 10, 5, 1};

	n = 1000 - n;
	for(int i = 0; i < 6; i++){
		int c = n / change[i];
		if(c > 0){
			n -= c * change[i];
			a += c;
		}
	}

	printf("%d", a);


	return 0;
}
