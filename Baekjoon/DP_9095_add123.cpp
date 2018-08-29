//9095 1,2,3 더하기 Dynamic Programming
#include <stdio.h>

int ott(int n, int result[]){	//123 가짓수 구하는 함수
	/*
		result[i] => 1+result[i-1] or 2+result[i-2] or 3+result[i-3]
	*/
	for(int i = 4; i <= n; i++) result[i] = result[i-1] + result[i-2] + result[i-3];

	return result[n];
}

int main(){
	int t;
	scanf("%d", &t);

	for(int i = 0; i < t; i++){
		int n;
		scanf("%d", &n);

		int result[n+1];

		result[1] = 1;
		result[2] = 2;
		result[3] = 4;

		if(n <= 3) printf("%d\n", result[n]);
		else printf("%d\n", ott(n, result));
	}


	return 0;
}
