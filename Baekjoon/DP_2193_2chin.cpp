//2193 이친수 Dynamic Programming
#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);

	/*
	e[1][0] = 0;
	e[1][1] = 1;
	e[2][0] = 1;
	e[2][1] = 0;

	e[n][0] = e[n-1][0] + e[n-1][1];
	e[n][1] = e[n-1][0];
=> 	e[n] = e[n-1][0] * 2 + e[n-1][1];
	*/

	long int e[n+1][2];	//e[자릿수][끝자리]

	e[1][0] = 0;
	e[1][1] = 1;

	for(int i = 2; i <= n; i++){
		e[i][0] = e[i-1][0] + e[i-1][1];
		e[i][1] = e[i-1][0];
	}

	printf("%ld", e[n][0] + e[n][1]);

	return 0;
}
