/*
15683 감시 DFS (Brute Force)
NxM 크기의 방과 5가지 종류의 CCTV가 있다. 1:>, 2:<>, 3:^>, 4:<^>, 5:<^v> 이다. CCTV는 90도씩 회전가능하고 벽은 뚫지못하고 cctv는 뚫는다.
CCTV로 볼 수 없는 사각지대가 최소가 될 때 사각지대의 크기를 구하기. (0은 공간, 6은 벽, 1~5는 CCTV의 종류)
입력 : 방의 크기 1 ≤ N, M ≤ 8 \n ~N M개의 방의 구성 요소
출력 : 사각지대의 최소 
*/
#include <stdio.h>

struct CCTV{
	int y;
	int x;
};

int n, m, min, tv_cnt, space;
int p[9][9];
CCTV c[9];

int rot_tv(int tv_idx, int d, int num){
	int y = c[tv_idx].y,
		x = c[tv_idx].x,
		tv = p[y][x],
		flag[4] = {0, };	//> v < ^

	if(tv == 1){			//>
		flag[d] = 1;
	}
	else if(tv == 2){		//<>
		flag[d] = 1;
		flag[(d+2)%4] = 1;
	}
	else if(tv == 3){		//^>
		flag[d] = 1;
		flag[(d+3)%4] = 1;
	}
	else if(tv == 4){		//<^>
		flag[d] = 1;
		flag[(d+2)%4] = 1;
		flag[(d+3)%4] = 1;
	}
	else if(tv == 5){		//<^v>
		flag[0] = flag[1] = flag[2] = flag[3] = 1;
	}

	if(flag[0]){	//>
		for(int j = x; j < m; j++){
			if(p[y][j] == 0){
				p[y][j] = 7;
				num--;
			}
			else if(p[y][j] == 6) break;
		}
	}

	if(flag[1]){	//v
		for(int i = y; i < n; i++){
			if(p[i][x] == 0){
				p[i][x] = 7;
				num--;
			}
			else if(p[i][x] == 6) break;
		}
	}

	if(flag[2]){	//<
		for(int j = x; j >= 0; j--){
			if(p[y][j] == 0){
				p[y][j] = 7;
				num--;
			}
			else if(p[y][j] == 6) break;
		}
	}

	if(flag[3]){	//^
		for(int i = y; i >= 0; i--){
			if(p[i][x] == 0){
				p[i][x] = 7;
				num--;
			}
			else if(p[i][x] == 6) break;
		}
	}

	return num;
}

void calc(int dir){
	int num = space;

	int dir_idx = 1, tv_idx = 0;
	for(int i = 1; i < tv_cnt; i++) dir_idx *= 10;

	for(int i = dir_idx; i > 0; i /= 10){
		int d = dir / i;
		dir -= d * i;

		num = rot_tv(tv_idx, d, num);
		tv_idx++;
	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) 
			if(p[i][j] == 7) 
				p[i][j] = 0;

	min = num < min ? num : min;

	return;
}

void dfs(int dir, int cnt){
	if(cnt == tv_cnt){
		calc(dir); 
		return;
	}

	for(int i = 0; i < 4; i++)
		dfs(dir * 10 + i, cnt+1);

	return;
}

int main(){
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &p[i][j]);
			if(p[i][j] < 6 && p[i][j] > 0){
				c[tv_cnt].y = i;
				c[tv_cnt].x = j;
				tv_cnt++;
			}
			else if(p[i][j] == 0) space++;
		}
	}
	min = space;

	if(tv_cnt > 0)
		for(int i = 0; i < 4; i++)
			dfs(i, 1);

	printf("%d", min);

	return 0;
}
