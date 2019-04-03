/*
NxM 크기의 방에서 로봇청소기가 청소를 한다. 먼저 자기 자리를 청소하고 반시계 방향으로 방향을 전환하고 현재 방향인 앞칸이 더러우면 그 칸으로 이동한다. 
만약 사방이 깨끗하거나 벽이면 후진한 후 다시 반시계 방향으로 검사한다. 후진 방향이 벽인 경우 중지한다. 이 로봇이 청소할 수 있는 칸의 개수 구하기
입력 : 방의 크기 3 ≤ N, M ≤ 50 \n 로봇의 좌표와 방향 (0123 : 북동남서) \n 방의 정보
출력 : 로봇이 청소할 칸의 개수
*/
#include <stdio.h>

int n, m, cnt;
int ry, rx, d;
int r[51][51];

int main(){
	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &ry, &rx, &d);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d", &r[i][j]);

	int flag = 0,
		ny = ry,
		nx = rx;
	while(1){
		flag = 0;

		if(r[ry][rx] == 0){
			r[ry][rx] = 2;
			cnt++;
		}

		while(flag < 4){
			d = (d + 3) % 4;

			switch(d){
				case 0: ny = ry - 1; nx = rx; break;
				case 1: ny = ry; nx = rx + 1; break;
				case 2: ny = ry + 1; nx = rx; break;
				case 3: ny = ry; nx = rx - 1; break;
			}

			if(r[ny][nx] == 0){
				ry = ny;
				rx = nx;

				break;
			}
			else flag++;
		}

		if(flag == 4){
			switch(d){
				case 0: ny = ry + 1; nx = rx; break;
				case 1: ny = ry; nx = rx - 1; break;
				case 2: ny = ry - 1; nx = rx; break;
				case 3: ny = ry; nx = rx + 1; break;
			}

			if(r[ny][nx] == 1) break;
			else{
				ry = ny;
				rx = nx;
			}
		}
	}

	printf("%d", cnt);
	
	return 0;
}
