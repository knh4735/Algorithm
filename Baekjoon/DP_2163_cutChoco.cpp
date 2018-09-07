/*
2163 초콜렛자르기 Dynamic Programming
NxM 크기의 초콜렛을 각각 1x1 조각으로 쪼개기 위한 최소 횟수 (한번에 두조각으로 나뉨)
입력 : 1 ≤ N, M ≤ 300
출력 : 모든 조각을 나누기 위해 쪼개는 최소 횟수
*/
#include <stdio.h>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	//쉬운 방법, 하지만 DP로 풀게따
	//printf("%d", n-1 + n *(m-1));

	int a[n+1];

	a[0] = 0;
	a[1] = m-1;

	for(int i = 2; i <= n; i++) a[i] = a[i/2] + a[i - i/2] + 1;

	printf("%d", a[n]);

	return 0;
}
