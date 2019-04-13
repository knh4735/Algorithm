/*
2105 디저트카페 DFS(Backtracking)
NxN 지도의 각 칸은 카페이고, 디저트의 종류가 입력된다. 대각선으로 움직이며 사각형 형태로 카페들을 탐색한다.
중복되는 디저트가 없도록 탐색할때 가장 다양한 디저트를 먹는 경우의 디저트 개수를 구하기
입력 : TC \n 지도 크기 4 ≤ N ≤ 20 \n ~N N개 각 디저트 카페의 디저트 종류 번호 1 ≤ K ≤ 100
출력 : 가장 다양한 디저트를 먹는 경우의 디저트 개수
*/
#include <stdio.h>
#include <set>
using namespace std;

int n, result;
int map[21][21];
int start[2];
set<int> s;


void dfs(int r, int c, int d, int state, int cnt){
	// <^  ^>  v>  <v
	int dr[4] = {-1, -1, 1, 1},
		dc[4] = {-1, 1, 1, -1},
		nd = (d+1) % 4;

	//printf("%d %d %d %d %d %d\n", map[r][c],r,c,d,state,cnt);

	//종료
	if((state == 3 && r + dr[d] == start[0] && c + dc[d] == start[1]) || (state == 2 && r + dr[nd] == start[0] && c + dc[nd] == start[1])){
		if(result < cnt) result = cnt;
		//printf("%d\n\n", cnt);

		return;
	}

	//회전
	if(state < 2 || (state == 2 && (r + c == start[0] + start[1] || r - c == start[0] - start[1]))){
		if(r + dr[nd] < n && c + dc[nd] < n && r + dr[nd] >= 0 && c + dc[nd] >= 0){
			int nr = r + dr[nd],
				nc = c + dc[nd];
			int org_size = s.size();
			
			s.insert(map[nr][nc]);
			if(s.size() > org_size){
				dfs(nr, nc, nd, state+1, cnt+1);

				s.erase(map[nr][nc]);
			}
		}
	}

	//직진
	if(!(state == 2 && (r + c == start[0] + start[1] || r - c == start[0] - start[1]))){
		if(r + dr[d] >= 0 && r + dr[d] < n && c + dc[d] >= 0 && c + dc[d] < n){
			int nr = r + dr[d],
				nc = c + dc[d];
			int org_size = s.size();
			
			s.insert(map[nr][nc]);
			if(s.size() > org_size){
				dfs(nr, nc, d, state, cnt+1);

				s.erase(map[nr][nc]);
			}

		}
	}

	return;
}



int main(){
	int T;
	scanf("%d", &T);

	for(int tc = 1; tc <= T; tc++){
		result = -1;

		scanf("%d", &n);

		for(int i = 0; i < n ; i++)
			for(int j = 0; j < n; j++)
				scanf("%d", &map[i][j]);

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				s.clear();
				s.insert(map[i][j]);
				start[0] = i;
				start[1] = j;
				for(int d = 0; d < 4; d++){
					//printf("\n\nStart %d %d\n", i, j);
					dfs(i, j, d, 0, 1);
				}
			}
		}

		printf("#%d %d\n", tc, result);
	}


	return 0;
}
