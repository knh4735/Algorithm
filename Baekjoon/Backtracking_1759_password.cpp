//1759 암호만들기 백트래킹
#include <stdio.h>

int l, c;

int findVownCon(char result[]){
	int conNum = 0, flag = 0;
	for(int i = 0; i < l; i++){
		switch(result[i]){
			case 'a' : flag =  1; break;
			case 'e' : flag =  1; break;
			case 'i' : flag =  1; break;
			case 'o' : flag =  1; break;
			case 'u' : flag =  1; break;
			default : conNum++;
		}
	}
	if(conNum >= 2 && flag == 1) return 1;
	else return 0;
}

//선택 가능 목록, 선택된 최대 인덱스, 선택된 목록, 현재 선택된 수
void choose(char list[], int idx, char result[], int cur){

	if(cur == l && findVownCon(result)) {
		for(int i = 0; i < l; i++) printf("%c", result[i]);
		printf("\n");
	}

	else if(l - cur <= c - idx - 1){	//남은 칸이 선택 가능한 수보다 적으면 ㅇ
		for(int i = idx + 1; i < c; i++){
			result[cur] = list[i];
			choose(list, i, result, cur + 1);
		}
	}

	return;
}


int main(){
	scanf("%d %d", &l, &c);

	char list[c];
	for(int i = 0; i < c; i++) scanf(" %c", &list[i]);

	//목록 정렬
	for(int i = 0; i < c; i++){
		for(int j = i; j < c; j++){
			if(list[i] > list[j]){
				char t = list[i];
				list[i] = list[j];
				list[j] = t;
			}
		}
	}

	char result[l];

	choose(list, -1, result, 0);

	return 0;
}
