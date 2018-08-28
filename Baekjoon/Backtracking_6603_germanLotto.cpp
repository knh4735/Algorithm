//6603 로또 백트래킹
#include <stdio.h>

int n;

//선택 가능 숫자 목록, 선택된 최대 숫자의 인덱스, 선택된 목록, 현재 선택된 수
void choose(int list[], int idx, int result[], int cur){
	if(cur == 6) {
		for(int i = 0; i < 6; i++) printf("%d ", result[i]);
		printf("\n");
	}
	else if(6 - cur <= n - idx - 1){	//남은 칸이 선택 가능한 수보다 적으면 ㅇ
		for(int i = idx + 1; i < n; i++){
			result[cur] = list[i];
			choose(list, i, result, cur + 1);
		}
	}
	return;
}


int main(){

	while(1){

		scanf(" %d", &n);

		if(n == 0) return 0;

		int list[n], result[6];

		for(int i = 0; i < n; i++) scanf(" %d", &list[i]);

		choose(list, -1, result, 0);

		printf("\n");
	}
	return 0;
}
