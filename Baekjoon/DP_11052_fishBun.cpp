/*
11052 붕어빵판매하기 Dynamic Programming
붕어빵 i개로 이루어진 세트메뉴의 가격이 Pi일때 남은 붕어빵 n개로 낼 수 있는 최대 수익 구하기
입력 : 남은 붕어빵 수 1 <= n <= 1000 \n 세트 가격 1 <= Pi <- 1000
출력 : 최대수익
*/
#include <stdio.h>

int n, p[1001], result[1001]; //result : i개를 팔때 최대 수익

int max(int q, int w){return (q > w ? q : w);}

int main(){
	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++) scanf("%d", &p[i]);

	result[0] = p[0] = 0;
	result[1] = p[1];

	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= i; j++){
			result[i] = max(result[i], result[i-j] + p[j]);
		}
	}

	printf("%d", result[n]);
	
	return 0;
}
