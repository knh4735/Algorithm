/*
1780 종이의개수 Devide & Conquer
NxN 행렬에 -1, 0, 1이 들어간다. 이를 적당한 크기로 자름
종이가 같은 수로 이루어 졌으면 그대로 사용, 그렇지 않은 경우 9개의 같은 크기인 행렬로 자르고 반복
이렇게해서 -1, 0, 1로만 이뤄진 종이의 수를 구하기
입력 : 1 ≤ N ≤ 3^7, N은 3^k \n ~N개의 정수
출력 : -1 \n 0 \n 1로만 채워진 종이의 수
*/
#include <stdio.h>

int n;
int num0, num1, num_1;
int p[2200][2200];

void cut(int g, int s, int u){
	int t = p[g][s], flag = 0;

	for(int i = g; i < g + u; i++){
		for(int j = s; j < s + u; j++){
			if(t != p[i][j]){
				flag = 1;
				break;
			}
		}

		if(flag == 1) break;
	}

	if(flag == 1){
		int nu = u/3;
		for(int i = g; i < g + u; i += nu) for(int j = s; j < s + u; j += nu) cut(i, j, nu);
		
	}

	else{
		switch(t){
			case -1 : num_1++; break;
			case 0 : num0++; break;
			case 1 : num1++;
		}
	}


	return;
}

int main(){
	scanf("%d", &n);

	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) scanf("%d", &p[i][j]);

	cut(0, 0, n);

	printf("%d\n%d\n%d", num_1, num0, num1);

	return 0;
}
