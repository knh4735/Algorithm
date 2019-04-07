/*
14499 주사위굴리기 Simulation
모든면이 0인 주사위가 NxM 지도의 특정 좌표에서 시작하여 명령에 따라 구른다. 주사위 바닥이 0이면 지도의 값을 복사하고 지도는 0으로, 0이 아니면 지도에 해당 값을 복사한다.
명령에 따라 이동하며 맨 위값을 출력하기
입력 : 지도의 크기 1 ≤ N, M ≤ 20, 주사위 시작 좌표 0 ≤ x ≤ N-1, 0 ≤ y ≤ M-1, 명령의 수 1 ≤ K ≤ 1,000 \n ~N 지도좌표 \n K개의 이동 방향 (1234 ><^v)
출력 : 각 이동 후 윗면의 값들 (지도를 벗어나는 명령은 무시)
*/
#include <stdio.h>

int n, m, x, y, k;
int map[21][21];
int dice[6];
/*
  2
4 1 3
  5
  0
 */

void move_dice(int d){
	int tmp = dice[0], nt, nb;	//next_top, next_bot
	switch(d){
		case 1: nb = 3; nt = 4;	break; //>
		case 2: nb = 4; nt = 3; break; //<
		case 3: nb = 2; nt = 5; break; //^
		case 4: nb = 5; nt = 2; break; //v
	}
	dice[0] = dice[nb];
	dice[nb] = dice[1];
	dice[1] = dice[nt];
	dice[nt] = tmp;

	return;
}

int main(){
	scanf("%d %d %d %d %d", &n, &m, &y, &x, &k);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &map[i][j]);
		}
	}

	int d;
	for(int move = 0; move < k; move++){
		scanf("%d", &d);

		int flag = 0;
		switch(d){
			case 1:	flag = x+1 < m ? 1 : 0; break;
			case 2:	flag = x-1 >= 0 ? 1 : 0; break;
			case 3: flag = y-1 >= 0 ? 1 : 0; break;
			case 4: flag = y+1 < n ? 1 : 0; break;
		}

		if(flag){
			switch(d){
				case 1:	x++; break;	//>
				case 2:	x--; break;	//<
				case 3: y--; break;	//^
				case 4: y++; break;	//v
			}

			move_dice(d);

			if(map[y][x] == 0) map[y][x] = dice[0];
			else{
				dice[0] = map[y][x];
				map[y][x] = 0;
			}

			printf("%d\n", dice[1]);
		}
	}

	return 0;
}
