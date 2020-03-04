// 1806 부분합 시간복잡도(투포인터)
#include <stdio.h>

int main(){
	int n, s;
	long long a[100001];
	
	scanf("%d %d", &n, &s);
	for(int i = 0; i < n; i++) scanf("%lld", &a[i]);

	int hd = 0, tl = 0;
	long long sum = a[0];
	int min = -1;
	while(tl < n){
		if(sum >= (long long)s){
			if(tl - hd < min || min == -1)
				min = tl - hd;

			sum -= a[hd];
			hd++;

		} else if(sum < (long long)s){
			tl++;
			sum += a[tl];
		}
	}

	printf("%d", min + 1);

	return 0;
}
