/*
11047 동전0 Greedy
n종류의 동전으로 k원을 만들기 위한 동전의 최소 개수 구하기
입력 : 1 <= n <= 10, 1 <= k <= 100000000 \n ~동전 종류 오름차순 1 <= Ai <= 1000000, A1 =1, Ai는 Ai-1의 배수
출력 : 필요한 동전의 최소 개수
*/
#include <stdio.h>

int main(){
	int n, k, cnt = 0;;
	scanf("%d %d", &n, &k);

	int coin[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &coin[i]);
	}

	for(int i = n - 1; i >= 0; i--){
		if(k == 0) break;

		int m = k / coin[i];
		if(m > 0){
			cnt += m;
			k -= m * coin[i];
		}
	}

	printf("%d", cnt);

	return 0;
}
