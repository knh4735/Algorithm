// 18809 Gaaaaaaaaaarden 삼성모의고사
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct POS {
	int r, c;
};

struct FIELD {
	int r, c, color;	// 0 green; 1 red;
};

int n, m, G, R, ans;
int garden[51][51];
vector<POS> grow;
vector<POS> green;
vector<POS> red;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void sim(){
	queue<FIELD> q;
	int map[51][51] = {0, };
	int flower = 0;

	int visit[51][51][2] = {0, };

	// queue 초기화
	for(auto cell: green){
		q.push({cell.r, cell.c, 0});
		visit[cell.r][cell.c][0] = 1;
		map[cell.r][cell.c] = 1;
	}

	for(auto cell: red){
		q.push({cell.r, cell.c, 1});
		visit[cell.r][cell.c][1] = 1;
		map[cell.r][cell.c] = 1;
	}
	
	while(!q.empty()){
		FIELD cell = q.front();
		q.pop();

		int time = map[cell.r][cell.c];

		// 꽃이 폈던 자리
		if(time == -1) continue;

		// printf("%d %d %d %d\n", time, cell.r, cell.c, cell.color);
		for(int i = 0; i < 4; i++){
			int r = cell.r + dr[i];
			int c = cell.c + dc[i];

			if(r < 0 || c < 0 || r >= n || c >= m || garden[r][c] == 0 || visit[r][c][cell.color] == 1) continue;

			// 꽃이 핌
			if(cell.color == 1 && map[r][c] == time + 1){
				// printf("Flower %d %d\n", r, c);
				map[r][c] = -1;
				flower++;

				continue;
			}

			if(map[r][c] != 0) continue;
			// printf("%d %d\n", r, c);

			visit[r][c][cell.color] = 1;
			map[r][c] = time + 1;
			q.push({r, c, cell.color});
		}
	}

	if(flower > ans){
		// printf("FLOWERS %d > %d\nGREEN ", flower, ans);
		// for(auto cell: green)
		// 	printf("(%d,%d) ", cell.r, cell.c);
		
		// printf("\nRED ");
		// for(auto cell: red)
		// 	printf("(%d,%d) ", cell.r, cell.c);
		
		// printf("\nMAP\n");
		// for(int i = 0; i < n; i++){
		// 	for(int j = 0; j < m; j++) printf("%2d ", map[i][j]);
		// 	printf("\n");
		// }
		// printf("\n");
		
		ans = flower;
	}
}

void select(int cur, int g_cnt, int r_cnt){
	if(g_cnt == G && r_cnt == R){
		sim();

		return;
	}
	if(G - g_cnt > grow.size() - cur - 1 || R - r_cnt > grow.size() - cur - 1) return;

	int i = cur + 1;
	if(g_cnt < G){
		green.push_back(grow[i]);
		select(i, g_cnt + 1, r_cnt);
		green.pop_back();
	}
	if(r_cnt < R){
		red.push_back(grow[i]);
		select(i, g_cnt, r_cnt + 1);
		red.pop_back();
	}
	if(grow.size() - i > G + R - g_cnt - r_cnt){
		select(i, g_cnt, r_cnt);
	}
}


int main(){
	scanf("%d %d %d %d", &n, &m, &G, &R);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &garden[i][j]);

			if(garden[i][j] == 2){
				grow.push_back({i, j});
			}
		}
	}

	select(0, 0, 0);

	green.push_back(grow[0]);
	select(0, 1, 0);
	green.pop_back();

	red.push_back(grow[0]);
	select(0, 0, 1);
	red.pop_back();


	printf("%d", ans);

	return 0;
}
