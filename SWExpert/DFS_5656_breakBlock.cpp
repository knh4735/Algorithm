/*
5656 벽돌깨기 DFS(Brute Force)
가로 W, 세로 H 판에 벽돌이 쌓여있고, 위에서 공을 N번 떨어트릴 수 있다. 벽돌에 써있는 숫자만큼 가로, 세로로 폭발한다.
N번 공을 떨어트렸을 때, 가장 많이 벽돌을 깬 경우 남은 벽돌 수 구하기
입력 : TC /n 공 떨어트릴 횟수 1 ≤ N ≤ 4, 판의 가로 세로 2 ≤ W ≤ 12, 2 ≤ H ≤ 15 \n ~H W개의 판 구성 정보
출력 : 벽돌이 가장 적게 남은 경우의 
*/
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

int n, w, h, total, result;
int map[16][13];
int seq[5];

void bomb(int tmp[][13], int r, int c){
	int v = tmp[r][c];
	tmp[r][c] = 0;
	if(v == 1) return;

	int r_src = r - v + 1,
		r_dst = r + v;

	for(int i = (r_src >= 0 ? r_src : 0) ; i < (r_dst < h ? r_dst : h); i++)
		if(tmp[i][c] > 0)
			bomb(tmp, i, c);


	int c_src = c - v + 1,
		c_dst = c + v;

	for(int i = (c_src >= 0 ? c_src : 0) ; i < (c_dst < w ? c_dst : w); i++)
		if(tmp[r][i] > 0) bomb(tmp, r, i);

	return;
}

int arrange(int tmp[][13]){
	int num = 0;
	queue<int> q;

	for(int j = 0; j < w; j++){
		for(int i = h-1; i >= 0; i--){
			if(tmp[i][j] > 0){
				q.push(tmp[i][j]);
				tmp[i][j] = 0;
			}
		}
			
		num += q.size();

		for(int i = h-1; i >= 0; i--){
			if(q.empty()) break;
				tmp[i][j] = q.front();
				q.pop();
		}
	}

	return num;
}

void drop_the_bead(){
	int num = 0;
	int tmp[16][13];
	memcpy(tmp, map, sizeof(map));

	for(int j = 0; j < n; j++){
		for(int i = 0; i < h; i++){
			if(tmp[i][seq[j]] != 0){
				bomb(tmp, i, seq[j]);
				break;
			}
		}

		num = arrange(tmp);
		if(num == 0) break;
	}

	if(result > num) result = num;

/*
	printf("\n");
	for(int i = 0; i < n; i++) printf("%d ", seq[i]);
	printf("\n");
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			printf("%d ", tmp[i][j]);
		}
		printf("\n");
	}
*/
	return;
}


void make_seq(int cnt){
	if(result == 0) return;
	if(cnt == n){
		drop_the_bead();
		return;
	}

	for(int i = 0; i < w; i++){
		seq[cnt] = i;
		make_seq(cnt+1);
	}

	return;
}


int main(){
	int T;
	scanf("%d", &T);

	for(int tc = 1; tc <= T; tc++){
		total = 0;
		memset(seq, -1, sizeof(seq));

		scanf("%d %d %d", &n, &w, &h);

		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				scanf("%d", &map[i][j]);
				total += map[i][j] > 0 ? 1 : 0;
			}
		}
		result = total;

		for(int i = 0; i < w; i++){
			seq[0] = i;
			make_seq(1);
		}

		printf("#%d %d\n", tc, result);
	}


	return 0;
}
