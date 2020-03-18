// 11653 소인수분해 정수론(소인수분해)
#include <stdio.h>
#include <cmath>
using namespace std;

int isPrime(int a){
	for(int i = 2; i <= sqrt(a); i++){
		if(a % i == 0) return 0;
	}

	return 1;
}

int main(){
	int n;
	scanf("%d", &n);

	for(int num = 2; num <= sqrt(n); num++){
		if(isPrime(num) == 0) continue;

		while(n % num == 0){
			printf("%d\n", num);
			n = n / num;
		}

		if(n == 1) break;
	}

	if(n > 1) printf("%d", n);

	return 0;
}
