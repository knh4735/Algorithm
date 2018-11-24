/*
1065 한수 브루트포스
각 자릿수가 등차수열을 이루는 수를 한수라고 한다 (135, 123 등)
입력 : 1 <= N <= 1000
출력 : 1 이상 N이하인 한수의 개수
*/

#include <stdio.h>

int isHansu(int n){
	if(n == 1000) return 0;
	int div = 1000, a[3] = {-1, -1, -1}, i = 0;
	while(n / div == 0) div /= 10;

	while(n > 0){
		a[i++] = n / div;
		n -= (n / div) * div;
		div /= 10;
	}

	if(a[2] == -1) a[2] = n;

	if(a[0] - a[1] == a[1] - a[2]) return 1;

	else return 0;
}

int main(){
	int n;
	scanf("%d", &n);

	if(n < 100) printf("%d", n);

	else{
		int cnt = 99;
		for(int i = 100; i <= n; i++){
			if(isHansu(i) == 1){
				//printf("%d\n", i);
				cnt++;
			}
		}

		printf("%d", cnt);
	}
	return 0;
}
