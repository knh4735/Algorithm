/*
1012 유기농배추 BFS
배추들이 인접해 심어져잇는 구역의 수를 구하기
입력 : 테스트케이스의 수 \n 가로길이 1 ≤ W ≤ 50, 세로길이 1 ≤ H ≤ 50, 배추의 개수 1 ≤ K ≤ 2500 \n 배추의 위치 X, Y
*/

#include <stdio.h>
#include <queue>
using namespace std;

struct cbg{
	int y;
	int x;
};

int main(){
	int t;
	scanf("%d", &t);

	for(int tc = 0; tc < t; tc++){
		int w, h, n, cnt = 0;
		scanf("%d %d %d", &w, &h, &n);

		int map[h+1][w+1];
		for(int i = 0; i <= h; i++) for(int j = 0; j <= w; j++) map[i][j] = -1;
		
		for(int i = 0; i < n; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			map[y][x] = 0;
  		}

		queue<cbg> cbgQ;
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				if(map[i][j] == 0){
					map[i][j] = 1;
					cbgQ.push((cbg) {i, j});

					while(!cbgQ.empty()){
						cbg c = cbgQ.front();
						cbgQ.pop();

						int k = c.y + 1, l = c.x;
						if(k < h && map[k][l] == 0){
							map[k][l] = 1;
							cbgQ.push((cbg){k, l});
						}

						k = c.y - 1, l = c.x;
						if(k >= 0 && map[k][l] == 0){
							map[k][l] = 1;
							cbgQ.push((cbg){k, l});
						}

						k = c.y, l = c.x + 1;
						if(l < w && map[k][l] == 0){
							map[k][l] = 1;
							cbgQ.push((cbg){k, l});
						}

						k = c.y, l = c.x - 1;
						if(l >= 0 && map[k][l] == 0){
							map[k][l] = 1;
							cbgQ.push((cbg){k, l});
						}
					}

					cnt++;
				}
			}
		}

		printf("%d\n", cnt);
	}

	return 0;
}
