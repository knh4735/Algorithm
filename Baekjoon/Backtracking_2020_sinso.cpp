//2023 신기한소수 백트래킹
#include <stdio.h>

int n;
int start[4] = {2, 3, 5, 7};

int verifySosu(int result[], int length){
	
	//배열을 수로 바꿈
	int k = 0;
	for(int i = 0; i < length; i++) k = k * 10 + result[i];

	if(k == 2) return 1;
	for(int i = 2; i < k; i++) if(k % i == 0) return 0;
	return 1;
}

void makeSinso(int result[], int length){	//결과 배열, 결과배열의 길이

	if(length == n){
		for(int i = 0; i < n; i++) printf("%d", result[i]);
		printf("\n");
	}
	else{
		length++;
		for(int i = 1; i < 10; i++){
			result[length - 1] = i;
			if(verifySosu(result, length)) makeSinso(result, length);
		}
	}

}

int main(){
	scanf("%d", &n);

	int result[n];

	for(int i = 0; i < 4; i++){
		result[0] = start[i];
		makeSinso(result, 1);
	}

	return 0;
}
