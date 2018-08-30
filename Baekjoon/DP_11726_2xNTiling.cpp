//11726 2xn타일링 Dynamic Programming
//2xN 직사각형을 1x2, 2x1 타일로 채우는 방법의 수
//1 <= n <= 1000
//방법의 수 % 10007
#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);

	int result[n+1];

	result[1] = 1;
	result[2] = 2;

	if(n < 3){
		printf("%d", result[n]);
		return 0;
	}

	//1칸적은거 끝에 세로한칸 추가 + 2칸 적은거 끝에 가로두칸 추가   (2칸적은거끝에 세로두칸 추가는 전자와 중복되는 경우가 발생)

	for(int i = 3; i <= n; i++){
		result[i] = (result[i-1] + result[i-2]) % 10007;
	}

	printf("%d", result[n]);

	return 0;
}
