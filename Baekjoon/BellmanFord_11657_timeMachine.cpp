// 11657 타임머신 그래프2(BellmanFord)
#include <stdio.h>
#include <vector>
using namespace std;

#define INF 2000000000

struct EDGE {
	int from, to, w;
};

int main(){
	int n, m;
	vector<EDGE> e;
	int dist[501];

	scanf("%d %d", &n, &m);

	int a, b, c;
	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &a, &b, &c);

		e.push_back({a, b, c});
	}

	for(int i = 0; i <= n; i++) dist[i] = INF;
	dist[1] = 0;

	// Relax
	for(int i = 0; i < n; i++)
		for(auto edge: e)
			if(dist[edge.from] != INF)
				dist[edge.to] = min(dist[edge.to], dist[edge.from] + edge.w);

	// 음의 사이클 검증
	for(auto edge: e){
		if(dist[edge.from] == INF) continue;
		if(dist[edge.to] > dist[edge.from] + edge.w){
			printf("-1");
			return 0;
		}
	}

	for(int i = 2; i <= n; i++){
		if(dist[i] == INF) printf("-1\n");
		else printf("%d\n", dist[i]);
	}
	
	return 0;
}
