// 2003 수들의합2 시간복잡도(투포인터)
#include <stdio.h>

int main(){
	int n, m;
	int a[10001];

	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int cnt = 0, sum = a[0];
	int hd = 0, tl = 0;
	while(1){
		if(sum == m){
			cnt++;
			if(tl == n-1) break;
			sum -= a[hd];
			hd++;
			tl++;
			sum += a[tl];
		} else if(sum > m){
			sum -= a[hd];
			hd++;
		} else {
			if(tl == n-1) break;
			tl++;
			sum += a[tl];
		}
	}

	printf("%d", cnt);

	return 0;
}
