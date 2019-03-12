/*
14502 연구실 BFS
0 빈칸, 1 벽, 2 바이러스. 3개의 벽을 추가로 세운 뒤에 바이러스가 닿지 않는 안전 구역의 최댓값 구하기
입력 : 3 <= 연구실의 가로, 세로 크기 <= 8 \n ~각 칸의 정보 (0,1,2)
출력 : 안전 구역의 최댓값
*/
#include <stdio.h>
#include <string.h>
#include <queue>

struct loc{
	int y;
	int x;
};

int n, m;
char l[9][9];
int cnt0 = 0;
loc pos[65];

int calSafe(){
	char tmp[9][9];
	memcpy(tmp, l, sizeof(l));

	std::queue<loc> q;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(tmp[i][j] == 2) q.push((loc){i, j});
		
	while(!q.empty()){
		int y = q.front().y, 
			x = q.front().x;
		q.pop();

		if(x-1 >= 0 && tmp[y][x-1] == 0){
			tmp[y][x-1] = 2;
			q.push((loc){y,x-1});
		}
		if(x+1 < m && tmp[y][x+1] == 0){
			tmp[y][x+1] = 2;
			q.push((loc){y,x+1});
		}
		if(y-1 >= 0 && tmp[y-1][x] == 0){
			tmp[y-1][x] = 2;
			q.push((loc){y-1,x});
		}
		if(y+1 < n && tmp[y+1][x] == 0){
			tmp[y+1][x] = 2;
			q.push((loc){y+1,x});
		}
	}

	int safe = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(tmp[i][j] == 0) safe++;

	return safe;
}

int main(){
	
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			scanf("%d", &l[i][j]);
			if(l[i][j] == 0){
				pos[cnt0].y = i;
				pos[cnt0].x = j;
				cnt0++;
			}
		}

	int max = 0;

	//벽 하나씩 세워보기
	for(int i = 0; i < cnt0-2; i++){
		l[pos[i].y][pos[i].x] = 1;
		for(int j = i + 1; j < cnt0-1; j++){
			l[pos[j].y][pos[j].x] = 1;
			for(int k = j + 1; k < cnt0; k++){
				l[pos[k].y][pos[k].x] = 1;
				//벽 3개 추가한 뒤에 BFS로 안전구역 세기
				int safe = calSafe();

				if(safe > max) max = safe;

				l[pos[k].y][pos[k].x] = 0;
			}
			l[pos[j].y][pos[j].x] = 0;
		}
		l[pos[i].y][pos[i].x] = 0;
	}

	printf("%d", max);


	return 0;
}
