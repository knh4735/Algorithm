// 11438 LCA2 그래프1(LCA)
#include <stdio.h>
#include <vector>
using namespace std;

vector<int> edge[100001];
int depth[100001]; // i번 노드의 깊이 (루트 = 0)
int visit[100001];
int parent[100001][17];	// i번 노드의 2^j번째 부모 (2^17 > 100,000)

void init(int node, int d){
	visit[node] = 1;
	depth[node] = d;

	for(int i = 0; i < edge[node].size(); i++){
		int child = edge[node][i];
		if(visit[child] == 1) continue;

		parent[child][0] = node;
		init(child, d+1);
	}
}

int lca(int p, int c){
	// c가 낮아야함
	if(depth[p] > depth[c]){
		int tmp = p;
		p = c; 
		c = tmp;
	}

	// depth 맞추기
	for(int i = 16; i >= 0; i--){
		if(depth[c] - depth[p] >= (1 << i)){
			c = parent[c][i];
		}
	}
	// printf("CHANGED %d %d\n", p, c);

	if(p == c) return p;

	// 높은곳부터 내려오며 서로 다른 값으로 변경. 조금씩 올라감
	for(int i = 16; i >= 0; i--){
		if(parent[p][i] != parent[c][i]){
			p = parent[p][i];
			c = parent[c][i];
			// printf("CHANGED %d %d\n", p, c);
		}
	}

	return parent[p][0];
}

int main(){
	int n, m;
	
	scanf("%d", &n);
	int q, w;
	for(int i = 1; i < n; i++){
		scanf("%d %d", &q, &w);
		edge[q].push_back(w);
		edge[w].push_back(q);
	}
	
	init(1, 0);

	for(int j = 1; j < 17; j++){
		for(int i = 1; i <= n; i++){
			// 노드의 2^j 번째 부모 = (2^j-1번째 부모)의 2^j-1번째 부모;;
			int grandfather = parent[i][j-1];
			parent[i][j] = parent[grandfather][j-1];
			// printf("%d ", parent[i][j]);
		}
		// printf("\n");
	}


	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d", &q, &w);

		printf("%d\n", lca(q, w));
	}


	return 0;
}
