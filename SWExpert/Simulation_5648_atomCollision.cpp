/*
5648 원자충돌시뮬레이션 Simulation
N개의 원소가 각각 한방향으로 움직인다. 충돌하는 원자들의 에너지가 방출된다. 원자들이 소멸하면서 방출되는 에너지의 합을 구하기.
입력 : 원자수 1 ≤ N ≤ 1,000 \n ~N 각 원자들의 좌표 -1,000≤x,y≤1,000), 방향 (0123 : 상하좌우), 에너지 (1≤K≤100)
출력 : 원자들의 이동을 시뮬레이션하여 방출된 에너지의 
*/
#include <stdio.h>
#include <string.h>

struct Atom{
	int y;
	int x;
	int d;	//0123 : ^v<>
	int e;	//energy
	int c;	//isCollided
};

int n, r, len;
int map[4001][4001];
Atom a[1001];

int main(){
	int T;
	scanf("%d", &T);

	for(int tc = 1; tc <= T; tc++){
		memset(map, -1, sizeof(map));
		r = 0;
		len = 0;
		
		scanf("%d", &n);

		for(int i = 0; i < n; i++){
			scanf("%d %d %d %d", &a[i].x, &a[i].y, &a[i].d, &a[i].e);
			a[i].c = 0;
			a[i].x *= 2;
			a[i].y *= 2;
			a[i].x += 2000;
			a[i].y += 2000;
			len++;
		}

		while(len > 0){
			//이동 및 충돌검사
			for(int i = 0; i < n; i++){
				if(a[i].c == 0){
					switch(a[i].d){
						case 0: a[i].y++; break;
						case 1: a[i].y--; break;
						case 2: a[i].x--; break;
						case 3: a[i].x++; break;
					}

					if(a[i].x > 4000 || a[i].y > 4000 || a[i].x < 0 || a[i].y < 0){
						a[i].c = 1;
						len--;
					}
					else if(a[i].c == 0){
						if(map[a[i].y][a[i].x] >= 0){
							a[map[a[i].y][a[i].x]].c = 2;
							a[i].c = 2;
						}
						else map[a[i].y][a[i].x] = i;
					}
				}
			}

			//충돌한놈들 삭제
			for(int i = 0; i < n; i++){
				if(a[i].c == 2){
					map[a[i].y][a[i].x] = -1;
					r += a[i].e;
					a[i].c = 1;
					len--;
				}
				else if(a[i].c == 0) map[a[i].y][a[i].x] = -1;
			}
		}

		printf("#%d %d\n", tc, r);
	}

	return 0;
}
