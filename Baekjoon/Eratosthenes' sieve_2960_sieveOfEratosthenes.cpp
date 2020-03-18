// 2960 에라토스테네스의체 정수론(에라토스테네스의체)
#include <stdio.h>

int main(){
	int n, k;
	scanf("%d %d", &n, &k);

	int cnt = 0, ans;
	int a[1001] = {0, };

	while(cnt < k){
		int min;
		for(int i = 2; i <= n; i++){
			if(a[i] == 0){
				min = i;
				break;
			}
		}

		for(int i = min; i <= n; i += min){
			if(a[i] == 1) continue;
			a[i] = 1;
			cnt++;
			if(cnt == k) ans = i;
		}
	}

	printf("%d", ans);
	
	return 0;
}
