// 1753 최단경로 그래프2(Dijkstra)
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

#define INF 2000000000

struct EDGE {
	int to, w;
};

struct ELEM {
	int node, dist;
};

bool operator < (ELEM a, ELEM b){
	return a.dist > b.dist;
}

int main(){
	vector<EDGE> edge[20001];
	priority_queue<ELEM> pq;
	int dist[20001];
	
	int v, e, start;
	scanf("%d %d %d", &v, &e, &start);

	int n1, n2, w;
	for(int i = 0; i < e; i++){
		scanf("%d %d %d", &n1, &n2, &w);
		edge[n1].push_back({n2, w});
	}

	for(int i = 1; i <= v; i++) dist[i] = INF;
	dist[start] = 0;
	pq.push({start, 0});

	while(!pq.empty()){
		ELEM elem = pq.top();
		pq.pop();
		
		if(dist[elem.node] < elem.dist) continue;

		for(auto i: edge[elem.node]){
			int distance = i.w + elem.dist;
			if(dist[i.to] <= distance) continue;

			dist[i.to] = distance;
			pq.push({i.to, distance});
		}
	}

	for(int i = 1; i <= v; i++){
		if(dist[i] == INF) printf("INF\n");
		else printf("%d\n", dist[i]);
	}

	return 0;
}
