/*
10972 다음순열 Implement (Permutation)
1부터 N까지의 수로 이루어진 순열에서 사전순으로 다음 순서의 순열을 구하기
입력 : 순열의 크기 1 ≤ N ≤ 10000 \n 순열
출력 : 입력받은 순열의 다음 순서인 순열 출력
*/
#include <stdio.h>
#include <algorithm>

int main(){
	int n;
	scanf("%d", &n);

	int s[10001], mark = -1;
	for(int i = 0; i < n; i++){
		scanf("%d", &s[i]);

		if(i > 0 && s[i] > s[i-1])
			mark = i - 1;
	}

	if(mark >= 0){
		int to = mark+1;
		for(int i = n-1; i > mark; i--)
			if(s[i] > s[mark] && s[to] > s[i])
				to = i;

		int tmp = s[to];
		s[to] = s[mark];
		s[mark] = tmp;

		std::sort(&s[mark+1], &s[n]);

		for(int i = 0; i < n; i++) printf("%d ", s[i]);
	}
	else printf("-1");

	return 0;
}
