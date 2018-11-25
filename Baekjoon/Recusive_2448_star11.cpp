/*
2448 별찍기11 재귀함수
높이가 주어질때 아래 같은 패턴의 별찍기 
     *                        
    * *                       
   *****       6을 입력한 경우               
  *     *                     
 * *   * *                    
***** *****    
입력 : 3*2^k (0 <= k <= 10)
출력 : 별찍기
*/
#include <stdio.h>
#include <stdlib.h>

int w, h;
char **s;

void fillTri(int k){	//현재 높이
	if(k >= h) return;

	//복사 범위
	int left = w / 2 - k + 1, right = w / 2 + k;

	//왼쪽 붙여넣기 범위 시작점, 오른쪽 붙여넣기 범위 끝점
	//int front = left - k, rear = right + k;

	for(int i = 0; i < k; i++){
		for(int j = left; j < right; j++){
			//왼쪽
			s[i + k][j - k] = s[i][j];

			//오른쪽
			s[i + k][j + k] = s[i][j];
		}
	}

	fillTri(2 * k);

	return;
}


int main(){
	scanf("%d", &h);
	w = 2 * h - 1;

	s = (char**)malloc(sizeof(char*) * h);
	for(int i = 0; i < h; i++){
		s[i] = (char*)malloc(sizeof(char) * w);
		for(int j = 0; j < w; j++) s[i][j] = ' ';
	}

	s[0][w/2] = '*';
	s[1][w/2 - 1] = s[1][w/2 + 1] = '*';
	s[2][w/2 - 2] = s[2][w/2 - 1] = s[2][w/2] =	s[2][w/2 + 1] = s[2][w/2 + 2] = '*';


	fillTri(3);

	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			printf("%c", s[i][j]);
		}
		printf("\n");
	}

	for(int i = 0; i < h; i++) free(s[i]);
	free(s);

	return 0;
}
