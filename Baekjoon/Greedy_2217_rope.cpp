/*
2217 로프 Greedy
n개의 로프로 들어올릴 수 있는 물건의 최대 중량 구하기, k개의 로프로 무게가 w인 물건을 들어올리면 각 로프에 w/k가 실린다
입력 : 로프의 수 1 <= n <= 100000 \n ~각 로프의 최대 중량 <= 10000
출력 : 최대 중량
*/
#include <stdio.h>
#include <functional>
#include <algorithm>

int main(){
	int n, m = 0;
	scanf("%d", &n);

	int w[n];
	for(int i = 0; i < n; i++) scanf("%d", &w[i]);

	std::sort(w, w+n, std::greater<int>());

	for(int i = 0; i < n; i++){
		int temp = w[i] * (i + 1);
		if(m < temp) m = temp;
	}

	printf("%d", m);
  
	return 0;
}
