/*
1915 가장큰정사각형 Dynamic Programming
0과 1로 이루어진 배열에서 1로 구성된 가장 큰 정사각형의 넓이 구하기
입력 : 배열의 크기 1 ≤ n, m ≤ 1,000 \n ~m n개의 배열 값 (0, 1)
출력 : 1로 구성된 가장 큰 정사각형의 넒
*/
#include <stdio.h>

struct matType{
	//값, 정사각형 시작 좌표
	char val;
	int srcR;
	int srcC;
};

int n, m, max = 0;
matType mat[1001][1001];

int cal(int curR, int curC, int srcR, int srcC){
	int flag = 1;

	//세로 검사 srcR~i, j
	for(int r = srcR; r < curR; r++){
		if(mat[r][curC].val == '0'){
			flag = 0;
			break;
		}
	}

	//가로 검사 i, srcC~j
	if(flag){
		for(int c = srcC; c < curC; c++){
			if(mat[curR][c].val == '0'){
				flag = 0;;
				break;
			}
		}
	}

	//정사각형
	if(flag){
		mat[curR][curC].srcR = srcR;
		mat[curR][curC].srcC = srcC;
		if(curR - srcR + 1 > max) max = curR - srcR + 1;
	}

  //정사각형 여부 
	return flag;
}

int main(){
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf(" %c", &mat[i][j].val);

			if(mat[i][j].val == '1'){
				max = 1;
				mat[i][j].srcR = i;
				mat[i][j].srcC = j;
			}
			else{
				mat[i][j].srcR = -1;
				mat[i][j].srcC = -1;
			}
		}
	}

	for(int i = 1; i < n; i++){
		for(int j = 1; j < m; j++){
			if(mat[i][j].val == '1' && mat[i-1][j-1].val == '1'){
				int srcR = mat[i-1][j-1].srcR,
					srcC = mat[i-1][j-1].srcC;
				
				//정사각형이 이어지지 않은 경우 현재까지의 최대 정사각형 다시 찾기 
				if(!cal(i, j, srcR, srcC)){
					for(int k = 1; k < i - srcR + 1; k++){
						if(cal(i, j, srcR + k, srcC + k)) break;
					}
				}

			}
		}
	}

	printf("%d", max*max);

	return 0;
}
