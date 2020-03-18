// 1735 분수합 정수론(유클리드호제법)
#include <stdio.h>

int euclidean(int a, int b){
	if(b > a) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	
	while(b > 0){
		int tmp = a;
		a = b;
		b = tmp % a;
	}

	return a;
}

int main(){
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);

	// numerator 분자, denominator 분모
	int num = a * d + b * c;
	int denom = b * d;
	int gcd = euclidean(num, denom);

	printf("%d %d", num / gcd, denom / gcd);

	return 0;
}
