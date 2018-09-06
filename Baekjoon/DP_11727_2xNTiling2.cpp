/*
11727 2xN타일링2 Dynamic Programming
2xN 직사각형을 2x1 타일과 2x2 타일로 채우는 경우의 수를 구하기
입력 : 1 <= n <= 1000
출력 : 채우는 방법의 수 % 10007
*/
#include <stdio.h>
#include <algorithm>

int main(){
	int n;
	scanf("%d", &n);

	int a[n+1];
	a[0] = 0;
	a[1] = 1;
	a[2] = 3;

	for(int i = 3; i <= n; i++){
		a[i] = (2 * a[i-2]+ a[i-1]) % 10007;
	}

	printf("%d", a[n]);

	return 0;
}
