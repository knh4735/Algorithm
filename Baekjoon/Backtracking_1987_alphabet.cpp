//1987 알파벳 Backtracking
//세로R x 가로C 판에서 각 칸에 알파벳이 써있고 죄측상단에서 시작하여 상하좌우 한칸씩 이동가능
//이동할칸에 씌인 알파벳은 지금까지 밟은적 없는 알파벳이여야 할때 말이 최대 몇칸까지 이동가능한지출력
//입력 : 1 <= R C <= 20 \n ~판에 들어갈 알파벳들
#include <stdio.h>

int max;
int r, c;
char pan[21][21];
char record[21 * 21];
char a[21 * 21];

int checkRecord(char record[], int num, char c){	//record의 현재 인덱스, 검사할 문자
	for(int i = 0; i < num; i++) if(record[i] == c) return 0;
	return 1;
}

void dfs(char pan[][21], int i, int j, char record[], int num){	//pan의 현재 인덱스, record의 현재 인덱스

	if(i + 1 < r && checkRecord(record, num, pan[i+1][j])){
		record[num] = pan[i+1][j];
		dfs(pan, i+1, j, record, num+1);
	}
	if(i - 1 >= 0 && checkRecord(record, num, pan[i-1][j])){
		record[num] = pan[i-1][j];
		dfs(pan, i-1, j, record, num+1);
	}
	if(j + 1 < c && checkRecord(record, num, pan[i][j+1])){
		record[num] = pan[i][j+1];
		dfs(pan, i, j+1, record, num+1);
	}
	if(j - 1 >= 0 && checkRecord(record, num, pan[i][j-1])){
		record[num] = pan[i][j-1];
		dfs(pan, i, j-1, record, num+1);
	}

	if(max < num) max = num;
}

int main(){
	scanf("%d %d", &r, &c);

	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			scanf(" %c", &pan[i][j]);
		}
	}

	record[0] = pan[0][0];
	dfs(pan, 0, 0, record, 1);

	printf("%d", max);

	return 0;
}
