//1463 1로만들기 Dynamic Programming
#include <stdio.h>

int min(int q, int w){return (q > w ? w : q);}

int main(){


	int n;
	scanf("%d", &n);

	int num[1000001];
	num[0] = 0;
	num[1] = 0;
	num[2] = 1;
	num[3] = 1;
  
	for(int i = 4; i <= n; i++){
		if(i % 3 == 0){
			if(i % 2 == 0) num[i] = min(min(num[i/3], num[i/2]), num[i-1]) + 1;
			else num[i] = min(num[i/3], num[i-1]) + 1;
		}
		else if(i % 2 == 0) num[i] = min(num[i/2], num[i-1]) + 1;
		else num[i] = num[i-1] + 1;
	}

	printf("%d", num[n]);

	return 0;
}
