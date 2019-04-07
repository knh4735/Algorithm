/*
3190 뱀 Simulation
NxN의 지도에서 뱀이 사과를 먹으면 늘어나고 자기자신이나 맵끝에 닿으면 게임이 끝난다. 0,0 오른쪽으로 시작.
L개의 방향 전환 명령이 주어진다. X초에 이동 후 D(시계 90도), L(반시계 90도)방향으로 꺾는다. 게임이 끝나는 시간 구하기
입력 : 지도 크기 2 ≤ N ≤ 100 \n 사과 개수 K 0 ≤ K ≤ 100 \n ~K 사과의 좌표 \n 방향 변환 횟수 L 1 ≤ L ≤ 100 \n ~L 시간, 방향 X ≤ 10000, L OR D
출력 : 명령에 따라 방향을 전환하며 게임을 진행할 때, 게임이 끝나는 시간
*/
#include <stdio.h>

int n, k, l, ts = 1;	//total_second
int sec[101], idx;
char c[101];
int map[101][101];		//d+1 or 0 : empty or -1 : apple
int y, x, ty, tx, d;	//tail_y, tail_x, d : 0123 >v<^

int main(){
	scanf("%d %d", &n, &k);

	int ay, ax;
	for(int i = 0; i < k; i++){
		scanf("%d %d", &ay, &ax);
		map[ay-1][ax-1] = -1;
	}
	map[0][0] = 1;

	scanf("%d", &l);
	for(int i = 0; i < l; i++) scanf("%d %c", &sec[i], &c[i]);

	while(1){
		int flag;
		switch(d){	//>v<^ test if end or snake-self and move
			case 0: flag = x + 1 <  n && map[y][x+1] <= 0 ? 1 : 0; x += flag; break;
			case 1: flag = y + 1 <  n && map[y+1][x] <= 0 ? 1 : 0; y += flag; break;
			case 2: flag = x - 1 >= 0 && map[y][x-1] <= 0 ? 1 : 0; x -= flag; break;
			case 3: flag = y - 1 >= 0 && map[y-1][x] <= 0 ? 1 : 0; y -= flag; break;
		}
		if(flag){
			if(map[y][x] == 0){		//no apple then cut tail
				int tmp = map[ty][tx];
				map[ty][tx] = 0;
				switch(tmp){
					case 1: tx++; break;	//>
					case 2: ty++; break;	//v
					case 3:	tx--; break;	//<
					case 4: ty--; break;	//^
				}
			}

			if(ts == sec[idx]){		//turn
				d += c[idx] == 'D' ? 1 : 3;
				d %= 4;
				idx++;
			}

			map[y][x] = d+1;
			ts++;

			/*
			printf("%d\n", d);
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++) printf("%2d ", map[i][j]);
				printf("\n");
			}
			*/
		}
		else break;	
	}

	printf("%d", ts);

	return 0;
}
