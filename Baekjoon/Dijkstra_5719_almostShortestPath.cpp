// 5719 거의최단경로 그래프2(Dijkstra)
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

#define INF 2000000000

struct EDGE {
	int to, cost;
};

struct ELEM {
	int node, dist;
	vector<int> path;
};

bool operator < (ELEM a, ELEM b){
	return a.dist > b.dist;
}

int main(){
	while(1){
		int n, m, s, d;
		vector<EDGE> e[501];
		priority_queue<ELEM> pq;
		int dist[501];

		scanf("%d %d", &n, &m);
		if(n == 0 && m == 0) break;

		scanf("%d %d", &s, &d);

		int u, v, p;
		for(int i = 0; i < m; i++){
			scanf("%d %d %d", &u, &v, &p);
			e[u].push_back({v, p});
		}

		for(int i = 0; i < n; i++) dist[i] = INF;
		dist[s] = 0;

		// 최단 경로 정보 저장
		vector<ELEM> sp;

		pq.push({s, 0, {s}});
		while(!pq.empty()){
			ELEM elem = pq.top();
			pq.pop();

			for(auto edge: e[elem.node]){
				int next = edge.to;
				int distance = elem.dist + edge.cost;

				if(dist[next] < distance) continue;

				vector<int> path = elem.path;
				path.push_back(next);

				if(next == d){
					if(dist[next] > distance) sp.clear();
					sp.push_back({next, distance, path});
				}
				dist[next] = distance;
				pq.push({next, distance, path});
			}
		}

		int no_road[501][501] = {0, };
		for(auto paths: sp){
			vector<int> path = paths.path;
			for(int i = 1; i < path.size(); i++){
				no_road[path[i-1]][path[i]] = 1;
			}
		}

		for(int i = 0; i < n; i++) dist[i] = INF;
		dist[s] = 0;

		int len = -1;
		pq.push({s, 0, {}});
		while(!pq.empty()){
			ELEM elem = pq.top();
			pq.pop();

			for(auto edge: e[elem.node]){
				int next = edge.to;
				if(no_road[elem.node][next] == 1) continue;

				int distance = elem.dist + edge.cost;
				if(dist[next] < distance) continue;

				dist[next] = distance;
				pq.push({next, distance, {}});
			}
		}

		if(dist[d] == INF) printf("-1\n");
		else printf("%d\n", dist[d]);
	}

	return 0;
}
