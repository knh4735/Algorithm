// 1854 K번째최단경로찾기 그래프2(Dijkstra)
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
};

bool operator < (ELEM a, ELEM b){
	return a.dist > b.dist;
}

int main(){
	int n, m, k;
	vector<EDGE> e[1001];
	priority_queue<ELEM> pq;
	priority_queue<int, vector<int>, less<int>> dist[1001];
	int check[1001] = {0, };

	scanf("%d %d %d", &n, &m, &k);
	
	int a, b, c;
	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &a, &b, &c);

		e[a].push_back({b, c});
	}

	dist[1].push(0);
	pq.push({1, 0});	

	while(!pq.empty()){
		ELEM elem = pq.top();
		pq.pop();

		for(auto edge: e[elem.node]){
			int next = edge.to;
			int d = edge.cost + elem.dist;

			if(dist[next].size() < k){
				dist[next].push(d);
				pq.push({edge.to, d});
			}
			else if(dist[next].top() > d){
				dist[next].pop();
				dist[next].push(d);
				pq.push({edge.to, d});
			}

		}
	}

	for(int i = 1; i <= n; i++){
		if(dist[i].size() < k) printf("-1\n");
		else printf("%d\n", dist[i].top());
	}

	return 0;
}
