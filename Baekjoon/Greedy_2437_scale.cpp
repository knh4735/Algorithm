/*
2437 저울 Greedy
양팔저울에 n개 추를 이용해 측정할 수 없는 물체의 무게의 최솟값을 구하기
입력 : 1 <= n <= 1000 \n 1 <= 추의 무게들 <= 1000000
출력 : 측정할 수 없는 무게의 최솟값
*/
#include <stdio.h>
#include <algorithm>

int n;

int main(){
	scanf("%d", &n);

	int w[n];
	for(int i = 0; i < n; i++) scanf("%d", &w[i]);

	std::sort(w, w+n);

	if(w[0] != 1){printf("1"); return 0;}

	int min = 0;
	for(int i = 0; i < n; i++){ //작은추들의 합 + 1보다 다음무게가 크면 그 사이 무게들을 잴 수 없음
		if(w[i] > min + 1) break;
		else min += w[i];
	}

	printf("%d", min + 1);


	return 0;
}
