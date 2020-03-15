// 3860 할로윈묘지 그래프2(BellmanFord)
#include <stdio.h>
#include <vector>
using namespace std;

#define INF 2000000000

struct POS {
	int x, y;
};

struct EDGE {
	POS from, to;
	int w;
};

int main(){
	while(1){
		int w, h, n;
		int dx[4] = {-1, 1, 0, 0};
		int dy[4] = {0, 0, -1, 1};
		int grave[31][31] = {0, };
		int warp[31][31] = {0, };
		vector<EDGE> e;

		
		scanf("%d %d", &w, &h);
		if(w == 0 && h == 0) break;

		scanf("%d", &n);
		int x1, y1, x2, y2, t;
		for(int i = 0; i < n; i++){
			scanf("%d %d", &x1, &y1);
			grave[x1][y1] = 1;
		}

		// 워프 추가
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &t);
			warp[x1][y1] = 1;
			e.push_back({{x1, y1}, {x2, y2}, t});
		}
		
		// edge, dist 초기화
		int dist[31][31];
		for(int x = 0; x < w; x++){
			for(int y = 0; y < h; y++){
				dist[x][y] = INF;
				if(grave[x][y] == 1 || warp[x][y] == 1 || (x == w-1 && y == h-1)) continue;

				int nx, ny;
				for(int k = 0; k < 4; k++){
					nx = x + dx[k];
					ny = y + dy[k];
					if(nx < 0 || ny < 0 || nx >= w || ny >= h || grave[nx][ny] == 1) continue;
					e.push_back({{x, y}, {nx, ny}, 1});
				}
			}
		}
		dist[0][0] = 0;

		for(int x = 0; x < w; x++){
			for(int y = 0; y < h; y++){
				if(grave[x][y] == 1) continue;
				for(auto edge: e){
					if(dist[edge.from.x][edge.from.y] == INF) continue;
					dist[edge.to.x][edge.to.y] = min(dist[edge.to.x][edge.to.y], dist[edge.from.x][edge.from.y] + edge.w);
				}
			}
		}

		// 음수 사이클 검증
		int flag = 0;
		for(auto edge: e){
			if(dist[edge.from.x][edge.from.y] == INF) continue;
			if(dist[edge.to.x][edge.to.y] > dist[edge.from.x][edge.from.y] + edge.w){
				flag = 1;
				break;
			}
		}

		if(flag == 1) printf("Never\n");
		else if(dist[w-1][h-1] == INF) printf("Impossible\n");
		else printf("%d\n", dist[w-1][h-1]);
	}

	return 0;
}
