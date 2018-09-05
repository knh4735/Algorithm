/*
2529 부등호 Backtracking
<와 >가 나열된 문자열, 부등호 사이사이에 서로다른 한자릿수를 넣어 모든 부등호 관계를 만족시키는 k+1자리의 수를 구해 최대,최소를 찾기
입력 : 부등호의 수 2 <= k <= 9 \n 부등호들
출력 : 부등호를 만족하는 최댓값 \n 최솟값
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
char list[11], max[11] = "0000000000", min[11] = "9999999999";

int dupCheck(int k, char l[], int len){	//중복시 0, ok 1
	for(int i = 0; i < len; i++) if(k == l[i]) return 0;
	return 1;
}

void makeSeq(int len, char l[]){

	if(len == n + 1){
		
		if(strncmp(max, l, len) < 0) strncpy(max, l, len);
		if(strncmp(min, l, len) > 0) strncpy(min, l, len);

		return;
	}

	if(list[len-1] == '<'){
		for(char k = '0'; k <= '9'; k++){
			if(dupCheck(k, l, len) == 1 && l[len-1] < k){
				l[len] = k;

				makeSeq(len + 1, l);
			}
		}
	}
	else if(list[len-1] == '>'){
		for(char k = '0'; k <= '9'; k++){
			if(dupCheck(k, l, len) == 1 && l[len-1] > k){
				l[len] = k;

				makeSeq(len + 1, l);
			}
		}
	}
}

int main(){
	scanf("%d", &n);

	for(int i = 0; i < n; i++) scanf(" %c", &list[i]);

	max[n+1] = min[n+1] = NULL;

	for(char i = '0'; i <= '9'; i++){
		char l[n+1];
		l[0] = i;

		makeSeq(1, l);	
	}

	printf("%s\n%s", max, min);

	return 0;
}
