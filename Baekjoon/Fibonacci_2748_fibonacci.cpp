// 2748 피보나치수2 시간복잡도
#include <stdio.h>

int main(){
	int n;
	long long a[2] = {0ll, 1ll};

	int idx = 2, f;

	scanf("%d", &n);

	if(n == 0){
		printf("0");
		return 0;
	} else if(n == 1){
		printf("1");
		return 0;
	}

	for(int i = 2; i <= n; i++)
		a[i%2] = a[0] + a[1];

	printf("%lld", a[n%2]);
	return 0;
}
