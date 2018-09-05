/*
1138 한줄로서기 Greedy
n명이 줄을 서고, 각자 자기 왼쪽에 자기보다 키가 큰사람의 수를 알고 있을때, 줄 순서를 구하기
입력: 1 <= n <= 10 \n 키가 i인 사람의 왼쪽에 선 키 i이상의 사람 수
출력 : 줄 순서대로 출력
*/
#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);

	int list[n], result[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &list[i]);
		result[i] = 0;
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(result[j] != 0) continue;

			if(list[i] == 0){
				result[j] = i + 1;
				break;
			}
			
			list[i]--;
		}
	}

	for(int i = 0; i < n; i++) printf("%d ", result[i]);

	return 0;
}
