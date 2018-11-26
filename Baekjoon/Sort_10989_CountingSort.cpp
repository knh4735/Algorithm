/*
10989 수정렬해보기3 CountingSort
계수정렬로 정렬하기
*/
#include <stdio.h>

int main(){
	//각 수가 배열에 몇 번 등장하는지 저장하는 배열
	int count[10001] = {0, };
	int n, a;
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &a);

		//입력된 수를 인덱스로 하는 배열 값++
		count[a]++;
	}

	for(int i = 0; i < 10001; i++){
		if(count[i] != 0){
			for(int j = 0; j < count[i]; j++) printf("%d\n", i);
		}
	}


	return 0;
}
