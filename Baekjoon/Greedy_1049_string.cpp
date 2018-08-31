/*
1049 기타줄 Greedy
기타줄 n개가 끊어졌을 때 m개의 브랜드에서 각 6줄패키지의 가격, 낱개의 줄의 가격이 주어질 때 n개의 줄을 가는 최소가격 구하기
입력 : 1 <= n <= 100, 1 <= m <= 50 \n ~각 브랜드별 0 <= 패키지 가격, 낱개의 가격 <= 1000
출력 : 최소 가격
*/
#include <stdio.h>
#include <algorithm>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	int pkg[m], each[m];
	for(int i = 0; i < m; i++) scanf("%d %d", &pkg[i], &each[i]);

	std::sort(pkg, pkg+m);
	std::sort(each, each+m);

	if(pkg[0] > each[0] * 6){
		printf("%d", each[0] * n);
		return 0;
	}

	if(pkg[0] < each[0] * (n % 6)){
		printf("%d", pkg[0] * (n / 6 + 1));
		return 0;
	}

	printf("%d", pkg[0] * (n / 6) + each[0] * (n % 6));

	return 0;
}
